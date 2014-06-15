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

#include "searchresourcetest.hpp"
#include <QtTest/QtTest>
#include "../include/client.hpp"
#include "adapters/mockadapter.hpp"

using namespace habrahabr;

void SearchResourceTest::checkUrlEncodedParameters() {
    MockAdapter mockAdapter;
    Client client(&mockAdapter);
    client.getSearchResource()->searchHubs("12 34");
    client.getSearchResource()->searchPosts(QString::fromUtf8("привет всем"), 123);

    QCOMPARE(mockAdapter.getAndRemoveFirstUrl(), QString("/hubs/search/12%2034"));
    QCOMPARE(mockAdapter.getAndRemoveFirstUrl(), QString("/search/posts/%D0%BF%D1%80%D0%B8%D0%B2%D0%B5%D1%82%20%D0%B2%D1%81%D0%B5%D0%BC?page=123"));
}
