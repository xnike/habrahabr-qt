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

#include "client.hpp"

namespace habrahabr {
    Client::Client(AbstractAdapter* adapter, QObject *parent) : QObject(parent), adapter(adapter),
        commentResource(new CommentResource(adapter, this)),
        companyResource(new CompanyResource(adapter, this)),
        feedResource(new FeedResource(adapter,this)),
        hubResource(new HubResource(adapter, this)),
        postResource(new PostResource(adapter, this)),
        searchResource(new SearchResource(adapter, this)),
        trackerResource(new TrackerResource(adapter, this)),
        userResource(new UserResource(adapter, this)) {
    }

    CommentResource* Client::getCommentResource() {
        return commentResource;
    }

    CompanyResource* Client::getCompanyResource() {
        return companyResource;
    }

    FeedResource* Client::getFeedResource() {
        return feedResource;
    }

    HubResource* Client::getHubResource() {
        return hubResource;
    }

    PostResource* Client::getPostResource() {
        return postResource;
    }

    SearchResource* Client::getSearchResource() {
        return searchResource;
    }

    TrackerResource* Client::getTrackerResource() {
        return trackerResource;
    }

    UserResource* Client::getUserResource() {
        return userResource;
    }
}
