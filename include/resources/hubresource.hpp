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

#ifndef HUBRESOURCE_HPP
#define HUBRESOURCE_HPP

#include "abstractresource.hpp"

namespace habrahabr {
    namespace resources {
        class HubResource : public AbstractResource {
            Q_OBJECT

        public:
            explicit HubResource(AbstractAdapter* adapter, QObject *parent = 0);

            Q_INVOKABLE void getFeedHabred(const QString alias, const int page = 1);
            Q_INVOKABLE void getFeedNew(const QString alias, const int page = 1);
            Q_INVOKABLE void getFeedUnhabred(const QString alias, const int page = 1);
            Q_INVOKABLE void getHubCategories();
            Q_INVOKABLE void getHubInfo(const QString alias);
            Q_INVOKABLE void getHubList(const int page = 1);
            Q_INVOKABLE void getHubOfCategory(const QString category, const int page = 1);
            Q_INVOKABLE void subscribeHub(const QString alias);
            Q_INVOKABLE void unsubscribeHub(const QString alias);

        signals:

        public slots:
        private:
            Q_DISABLE_COPY(HubResource)
        };
    }
}

// TODO add checking alias for regexp '/^[a-z0-9\-_]+$/i'

#endif
