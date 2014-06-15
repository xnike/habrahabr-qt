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

#include "tests/adapters/mockadapter.hpp"

MockAdapter::MockAdapter(QObject *parent) : AbstractAdapter(parent) {
}

QString MockAdapter::getAndRemoveFirstUrl() {
    QString url = urls.first();
    urls.removeFirst();
    return url;
}

AbstractEntity* MockAdapter::doDelete(QString url) {
    urls << url;
    return NULL;
}

AbstractEntity* MockAdapter::doGet(QString url) {
    urls << url;
    return NULL;
}

AbstractEntity* MockAdapter::doPost(QString url, QVariantMap) {
    urls << url;
    return NULL;
}

AbstractEntity* MockAdapter::doPut(QString url, QVariantMap) {
    urls << url;
    return NULL;
}
