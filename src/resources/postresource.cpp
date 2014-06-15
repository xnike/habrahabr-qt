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

#include "include/resources/postresource.hpp"

namespace habrahabr {
    namespace resources {
        PostResource::PostResource(AbstractAdapter* adapter, QObject* parent) : AbstractResource(adapter, parent) {
        }

        void PostResource::addPostToFavorite(const int postId) {
            adapter->doGet(QString("/post/%1/favorite").arg(postId));
        }

        void PostResource::getPost(const int postId) {
            adapter->doGet(QString("/post/%1").arg(postId));
        }

        void PostResource::removePostFromFavorite(const int postId) {
            adapter->doDelete(QString("/post/%d/favorite").arg(postId));
        }

        void PostResource::vote(const int postId, PostResource::VoteType voteType) {
            QVariantMap data;
            data["vote"] = voteType;
            adapter->doPut(QString("/post/%d/vote").arg(postId), data);
        }

        void PostResource::voteMinus(const int postId) {
            vote(postId, PostResource::VOTE_MINUS);
        }

        void PostResource::voteNeutral(const int postId) {
            vote(postId, PostResource::VOTE_NEUTRAL);
        }

        void PostResource::votePlus(const int postId) {
            vote(postId, PostResource::VOTE_PLUS);
        }
    }
}
