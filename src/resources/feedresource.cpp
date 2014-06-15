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

#include "include/resources/feedresource.hpp"

namespace habrahabr {
    namespace resources {
        FeedResource::FeedResource(AbstractAdapter* adapter, QObject* parent) : AbstractResource(adapter, parent) {
        }

        void FeedResource::getFeedHabred(const int page) {
            adapter->doGet(QString("/feed/habred?page=%1").arg(page));
        }

        void FeedResource::getFeedNew(const int page) {
            adapter->doGet(QString("/feed/new?page=%1").arg(page));
        }

        void FeedResource::getFeedUnhabred(const int page) {
            adapter->doGet(QString("/feed/unhabred?page=%1").arg(page));
        }
    }
}
