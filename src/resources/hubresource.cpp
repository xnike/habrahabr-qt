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

#include "include/resources/hubresource.hpp"

namespace habrahabr {
    namespace resources {
        HubResource::HubResource(AbstractAdapter* adapter, QObject* parent) : AbstractResource(adapter, parent) {
        }

        void HubResource::getFeedHabred(const QString alias, const int page) {
            adapter->doGet(QString("/hub/%1/habred?page=%2").arg(alias).arg(page));
        }

        void HubResource::getFeedNew(const QString alias, const int page) {
            adapter->doGet(QString("/hub/%1/new?page=%2").arg(alias).arg(page));
        }

        void HubResource::getFeedUnhabred(const QString alias, const int page) {
            adapter->doGet(QString("/hub/%1/unhabred?page=%2").arg(alias).arg(page));
        }

        void HubResource::getHubCategories() {
            adapter->doGet("/hubs/categories");
        }

        void HubResource::getHubInfo(const QString alias) {
            adapter->doGet(QString("/hub/%1/info").arg(alias));
        }

        void HubResource::getHubList(const int page) {
            adapter->doGet(QString("/hubs?page=%1").arg(page));
        }

        void HubResource::getHubOfCategory(const QString category, const int page) {
            adapter->doGet(QString("/hubs/categories/%1?page=%2").arg(category).arg(page));
        }

        void HubResource::subscribeHub(const QString alias) {
            adapter->doPut(QString("/hub/%1").arg(alias), QVariantMap());
        }

        void HubResource::unsubscribeHub(const QString alias) {
            adapter->doDelete(QString("/hub/%1").arg(alias));
        }
    }
}
