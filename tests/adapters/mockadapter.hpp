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

#ifndef MOCKADAPTER_HPP
#define MOCKADAPTER_HPP

#include <QList>
#include "../../include/adapters/abstractadapter.hpp"

using namespace habrahabr::adapters;

class MockAdapter : public AbstractAdapter {
    Q_OBJECT

public:
    explicit MockAdapter(QObject *parent = 0);

    QString getAndRemoveFirstUrl();

    AbstractEntity* doDelete(QString url);
    AbstractEntity* doGet(QString url);
    AbstractEntity* doPost(QString url, QVariantMap data);
    AbstractEntity* doPut(QString url, QVariantMap data);

private:
    QList<QString> urls;
};

#endif
