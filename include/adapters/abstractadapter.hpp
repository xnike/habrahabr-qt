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

#ifndef ABSTRACTADAPTER_HPP
#define ABSTRACTADAPTER_HPP

#include <QObject>
#include <QNetworkReply>
#include <QSslError>
#include <QVariantMap>
#include "../entities/abstractentity.hpp"

using namespace habrahabr::entities;

namespace habrahabr {
    namespace adapters {
        class AbstractAdapter : public QObject {
            Q_OBJECT
            Q_PROPERTY(QString client READ getClient WRITE setClient NOTIFY clientChanged)
            Q_PROPERTY(QString endpoint READ getEndpoint WRITE setEndpoint NOTIFY endpointChanged)
            Q_PROPERTY(QString token READ getToken WRITE setToken NOTIFY tokenChanged)

        public:
            explicit AbstractAdapter(QObject *parent = 0);

            Q_INVOKABLE void setClient(QString client);
            Q_INVOKABLE void setEndpoint(QString endpoint);
            Q_INVOKABLE void setToken(QString token);

            QString getClient();
            QString getEndpoint();
            QString getToken();

            virtual AbstractEntity* doDelete(QString url) = 0;
            virtual AbstractEntity* doGet(QString url) = 0;
            virtual AbstractEntity* doPost(QString url, QVariantMap data) = 0;
            virtual AbstractEntity* doPut(QString url, QVariantMap data) = 0;

        signals:
            void clientChanged(QString);
            void endpointChanged(QString);
            void tokenChanged(QString);

        protected slots:
            void sslErrors(QNetworkReply *reply, const QList<QSslError> & errors);

        private:
            QString client;
            QString endpoint;
            QString token;
        };
    }
}

#endif
