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

#ifndef REQUESTHANDLER_HPP
#define REQUESTHANDLER_HPP

#include <QThread>
#include <QTcpSocket>
#include "../../include/adapters/syncadapter.hpp"
#include "rule.hpp"

class RequestHandler : public QThread {
    Q_OBJECT

public:
    explicit RequestHandler(QMap<QPair<QString, SyncAdapter::RequestType>, Rule>* rules, bool useSSL, int socketDescriptor, QObject* parent = 0);

    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    Rule getRule(QString line);

private:
    QMap<QPair<QString, SyncAdapter::RequestType>, Rule>* rules;
    bool useSSL;
    int socketDescriptor;
};

#endif
