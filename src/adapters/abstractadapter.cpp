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

#include "include/adapters/abstractadapter.hpp"
#include <QDebug>

namespace habrahabr {
    namespace adapters {
        AbstractAdapter::AbstractAdapter(QObject* parent) : QObject(parent) {
        }

        QString AbstractAdapter::getClient() {
            return client;
        }

        QString AbstractAdapter::getEndpoint() {
            return endpoint;
        }

        QString AbstractAdapter::getToken() {
            return token;
        }

        void AbstractAdapter::setClient(QString client) {
            if (this->client != client) {
                this->client = client;
                emit clientChanged(client);
            }
        }

        void AbstractAdapter::setEndpoint(QString endpoint) {
            if (this->endpoint != endpoint) {
                this->endpoint = endpoint;
                emit endpointChanged(endpoint);
            }
        }

        void AbstractAdapter::setToken(QString token) {
            if (this->token != token) {
                this->token = token;
                emit tokenChanged(token);
            }
        }

        void AbstractAdapter::sslErrors(QNetworkReply *reply, const QList<QSslError> & errors) {
            qDebug() << "Ignoring sslErrors " << errors << "for" << reply;
            reply->ignoreSslErrors(errors);
        }
    }
}
