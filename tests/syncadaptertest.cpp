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

#include "syncadaptertest.hpp"
#include <QDebug>
#include <QtTest/QtTest>
#include "backend/mockbackend.hpp"
#include "../include/client.hpp"
#include "../include/adapters/syncadapter.hpp"
#include "../include/entities/abstractentity.hpp"

using namespace habrahabr;

void SyncAdapterTest::checkWithSSL() {
    Rule rule1(SyncAdapter::PUT, "/comments/20", "{ok}");

    MockBackend mockBackend(true, true);
    mockBackend.listen(QHostAddress::Any, 12345);
    mockBackend.addRule(rule1);

    SyncAdapter syncAdapter("client", "token", "https://127.0.0.1:12345");
    Client client(&syncAdapter);

    QCOMPARE(client.getCommentResource()->postComment(20, "qwerty", 10)->getValue(), QString("{ok}"));
}

void SyncAdapterTest::checkWithoutSSL() {
    Rule rule1(SyncAdapter::GET, "/hubs/search/12345", "{hello}");
    Rule rule2(SyncAdapter::GET, "/hubs/search/12321", "{hi}");
    Rule rule3(SyncAdapter::PUT, "/comments/20", "{ok}");

    MockBackend mockBackend(false, false);
    mockBackend.listen(QHostAddress::Any, 12345);
    mockBackend.addRule(rule1);
    mockBackend.addRule(rule2);
    mockBackend.addRule(rule3);

    SyncAdapter syncAdapter("client", "token", "http://127.0.0.1:12345");
    Client client(&syncAdapter);

    QCOMPARE(client.getCommentResource()->postComment(20, "qwerty", 10)->getValue(), QString("{ok}"));
    QCOMPARE(client.getSearchResource()->searchHubs("12321")->getValue(), QString("{hi}"));
    QCOMPARE(client.getSearchResource()->searchHubs("12345")->getValue(), QString("{hello}"));
}
