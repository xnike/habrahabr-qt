/* Copyright (c) 2014 Nikolay Khramchenkov <xnike.me@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "tests/backend/requesthandler.hpp"
#include <QDebug>
#include <QSslSocket>
#include <QStringList>

RequestHandler::RequestHandler(QMap<QPair<QString, SyncAdapter::RequestType>, Rule>* rules, bool useSSL, int socketDescriptor, QObject* parent) : QThread(parent), rules(rules), useSSL(useSSL), socketDescriptor(socketDescriptor) {
}

Rule RequestHandler::getRule(QString line) {
    QStringList list = line.split(" ");
    SyncAdapter::RequestType requestType = ("DELETE" == list.at(0) ? SyncAdapter::DELETE : "GET" == list.at(0) ? SyncAdapter::GET : SyncAdapter::PUT);

    return rules->value(QPair<QString, SyncAdapter::RequestType>(list.at(1), requestType));
}

void RequestHandler::run() {
    QSslSocket tcpSocket;

    if (useSSL) {
        // tcpSocket.setProtocol(QSsl::SslV2);
        tcpSocket.setPrivateKey("../habrahabr-qt/tests/backend/certificate/mockbackend.key");
        tcpSocket.setLocalCertificate("../habrahabr-qt/tests/backend/certificate/mockbackend.crt");
    }

    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket.error());
        return;
    } else {
        if (useSSL) {
            tcpSocket.startServerEncryption();

            if (!tcpSocket.waitForEncrypted()) {
                emit error(tcpSocket.error());
                return;
            }
        }
    }

    if (!tcpSocket.waitForReadyRead()) {
        emit error(tcpSocket.error());
        return;
    }

    QByteArray income = tcpSocket.readLine();
    qDebug() << "Received: " << QString(income);
    QByteArray data = tcpSocket.readAll();
    qDebug() << "Received others: " << QString(data);

    Rule rule = getRule(income);

    tcpSocket.write(QString("HTTP/1.1 %1 %2\r\n").arg(200).arg("OK").toAscii());
    tcpSocket.write(QString("Connection : close\r\n").toUtf8());
    tcpSocket.write(QString("Content-Length : %1\r\n").arg(rule.getResponse().size()).toUtf8());
    tcpSocket.write(QString("Content-Type : text/json; charset=UTF-8\r\n").toUtf8());
    tcpSocket.write(QString("\r\n").toUtf8());
    tcpSocket.write(rule.getResponse().toUtf8());
    tcpSocket.flush();
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
