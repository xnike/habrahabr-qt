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

#include "include/entities/abstractentity.hpp"
#include "include/resources/searchresource.hpp"
#include <QUrl>

namespace habrahabr {
    namespace resources {
        SearchResource::SearchResource(AbstractAdapter* adapter, QObject* parent) : AbstractResource(adapter, parent) {
        }

        AbstractEntity* SearchResource::searchHubs(const QString query) {
            return adapter->doGet(QString("/hubs/search/%1").arg(QString(QUrl::toPercentEncoding(query))));
        }

        AbstractEntity* SearchResource::searchPosts(const QString string, const int page) {
            return adapter->doGet(QString("/search/posts/%1?page=%2").arg(QString(QUrl::toPercentEncoding(string))).arg(page));
        }

        AbstractEntity* SearchResource::searchUsers(const QString string, const int page) {
            return adapter->doGet(QString("/search/users/%1?page=%2").arg(QString(QUrl::toPercentEncoding(string))).arg(page));
        }
    }
}
