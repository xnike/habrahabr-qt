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

#ifndef MOCKBACKEND_HPP
#define MOCKBACKEND_HPP

#include <QTcpServer>
#include "rule.hpp"
#include "../../include/adapters/syncadapter.hpp"

using namespace habrahabr::adapters;

class MockBackend : public QTcpServer {
    Q_OBJECT

public:
    explicit MockBackend(const bool useSSL = false, const bool useThreadedHandlers = true, QObject* parent = 0);

    Q_INVOKABLE void addRule(Rule& rule);
    Q_INVOKABLE void clearRules();

protected:
    void incomingConnection(int socketDescriptor);

private:
    QMap<QPair<QString, SyncAdapter::RequestType>, Rule> rules;
    bool useSSL;
    bool useThreadedHandlers;
};

#endif
