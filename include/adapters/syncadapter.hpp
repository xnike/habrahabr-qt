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

#ifndef SYNCADAPTER_HPP
#define SYNCADAPTER_HPP

#include "abstractadapter.hpp"
#include <QEventLoop>
#include <QtNetwork/QNetworkAccessManager>


namespace habrahabr {
    namespace adapters {
        class SyncAdapter : public AbstractAdapter {
            Q_OBJECT

        public:
            explicit SyncAdapter(QString client, QString token, QString endpoint = "https://api.habrahabr.ru/v1", QObject* parent = 0);

            AbstractEntity* doDelete(QString url);
            AbstractEntity* doGet(QString url);
            AbstractEntity* doPost(QString url, QVariantMap data);
            AbstractEntity* doPut(QString url, QVariantMap data);

            enum RequestType{DELETE, GET, POST, PUT};

        signals:

        //private slots:
        //    void replyReceived(QNetworkReply *reply);

        private:
            AbstractEntity* process(SyncAdapter::RequestType requestType, QString path, QVariantMap data = QVariantMap());
            AbstractEntity* processReply(QNetworkReply *reply);

        private:
            QEventLoop *eventLoop;
            QNetworkAccessManager* networkAccessManager;
        };
    }
}

// TODO add sync & async mode selector

#endif
