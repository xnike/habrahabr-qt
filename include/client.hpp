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

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QObject>
#include "adapters/abstractadapter.hpp"
#include "resources/commentresource.hpp"
#include "resources/companyresource.hpp"
#include "resources/feedresource.hpp"
#include "resources/hubresource.hpp"
#include "resources/postresource.hpp"
#include "resources/searchresource.hpp"
#include "resources/trackerresource.hpp"
#include "resources/userresource.hpp"

using namespace habrahabr::adapters;
using namespace habrahabr::resources;

namespace habrahabr {
    class Client : public QObject {
        Q_OBJECT

    public:
        explicit Client(AbstractAdapter* adapter, QObject *parent = 0);

        Q_INVOKABLE CommentResource* getCommentResource();
        Q_INVOKABLE CompanyResource* getCompanyResource();
        Q_INVOKABLE FeedResource* getFeedResource();
        Q_INVOKABLE HubResource* getHubResource();
        Q_INVOKABLE PostResource* getPostResource();
        Q_INVOKABLE SearchResource* getSearchResource();
        Q_INVOKABLE TrackerResource* getTrackerResource();
        Q_INVOKABLE UserResource* getUserResource();

    signals:

    public slots:
    private:
        AbstractAdapter* adapter;
        CommentResource* commentResource;
        CompanyResource* companyResource;
        FeedResource* feedResource;
        HubResource* hubResource;
        PostResource* postResource;
        SearchResource* searchResource;
        TrackerResource* trackerResource;
        UserResource* userResource;
    };
}

#endif
