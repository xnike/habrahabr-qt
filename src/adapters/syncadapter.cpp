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

#include "include/adapters/syncadapter.hpp"
#include <QDebug>
#include <QtNetwork/QNetworkRequest>
#include <QNetworkReply>

namespace habrahabr {
    namespace adapters {
        SyncAdapter::SyncAdapter(QString client, QString token, QString endpoint, QObject* parent) : AbstractAdapter(parent),
            eventLoop(new QEventLoop()), networkAccessManager(new QNetworkAccessManager(this)) {
            setClient(client);
            setEndpoint(endpoint);
            setToken(token);
            connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), eventLoop, SLOT(quit()));
            connect(networkAccessManager, SIGNAL(sslErrors(QNetworkReply*, QList<QSslError>)), this, SLOT(sslErrors(QNetworkReply*, QList<QSslError>)));
            // connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyReceived(QNetworkReply*)));
        }

        AbstractEntity* SyncAdapter::doDelete(QString url) {
            return process(SyncAdapter::DELETE, url);
        }

        AbstractEntity* SyncAdapter::doGet(QString url) {
            return process(SyncAdapter::GET, url);
        }

        AbstractEntity* SyncAdapter::doPost(QString url, QVariantMap data) {
            return process(SyncAdapter::POST, url, data);
        }

        AbstractEntity* SyncAdapter::doPut(QString url, QVariantMap data) {
            return process(SyncAdapter::PUT, url, data);
        }

        AbstractEntity* SyncAdapter::process(SyncAdapter::RequestType requestType, QString url, QVariantMap data) {
            QNetworkRequest request(QString("%1%2").arg(getEndpoint()).arg(url));
            request.setRawHeader(QString("client").toUtf8(), getClient().toUtf8());
            request.setRawHeader(QString("token").toUtf8(), getToken().toUtf8());
            QNetworkReply* reply = NULL;

            if (SyncAdapter::DELETE == requestType){
                reply = networkAccessManager->deleteResource(request);
            } else if (SyncAdapter::GET == requestType) {
                reply = networkAccessManager->get(request);
            } else if (SyncAdapter::POST == requestType || SyncAdapter::PUT == requestType) {
                QUrl params;

                foreach (const QString& key, data.keys()) {
                    params.addQueryItem(key, data.value(key).toString());
                }

                request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
                reply = SyncAdapter::POST == requestType ? networkAccessManager->post(request, params.encodedQuery()) : networkAccessManager->put(request, params.encodedQuery());
            }

            eventLoop->exec();
            return processReply(reply);
        }

        AbstractEntity* SyncAdapter::processReply(QNetworkReply *reply) {
            qDebug() << "Reply received. Response code: " << reply->error();

            if (QNetworkReply::NoError == reply->error()) {
                return new AbstractEntity(QString(reply->readAll()), this);
            } else {
                return new AbstractEntity(this);
            }
        }
    }
}
