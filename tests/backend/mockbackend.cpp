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

#include "mockbackend.hpp"
#include "requesthandler.hpp"

MockBackend::MockBackend(const bool useSSL, bool useThreadedHandlers, QObject* parent) : QTcpServer(parent), useSSL(useSSL), useThreadedHandlers(useThreadedHandlers) {
}

void MockBackend::addRule(Rule& rule) {
    rules.insert(QPair<QString, SyncAdapter::RequestType>(rule.getEndpoint(), rule.getRequestType()), rule);
}

void MockBackend::clearRules() {
    rules.clear();
}

/**
 * @brief MockBackend::incomingConnection
 * Note: useThreadedHandlers must be true in case of usage habrahabr::adapters::SyncAdapter and useSSL = true,
 * because habrahabr::adapters::AbstractAdapter::sslErrors() executes after exiting on tcpSocket.waitForReadyRead()
 * @param socketDescriptor
 */
void MockBackend::incomingConnection(int socketDescriptor) {
    if (useThreadedHandlers) {
        RequestHandler* requestHandler = new RequestHandler(&rules, useSSL, socketDescriptor, this);
        connect(requestHandler, SIGNAL(finished()), requestHandler, SLOT(deleteLater()));
        requestHandler->start();
    } else {
        RequestHandler requestHandler(&rules, useSSL, socketDescriptor, this);
        requestHandler.run();
    }
}
