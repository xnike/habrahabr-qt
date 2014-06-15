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

#ifndef POSTRESOURCE_HPP
#define POSTRESOURCE_HPP

#include "abstractresource.hpp"

namespace habrahabr {
    namespace resources {
        class PostResource : public AbstractResource {
            Q_OBJECT

        public:
            explicit PostResource(AbstractAdapter* adapter, QObject* parent = 0);

            Q_INVOKABLE void addPostToFavorite(const int postId);
            Q_INVOKABLE void getPost(const int postId);
            Q_INVOKABLE void removePostFromFavorite(const int postId);
            Q_INVOKABLE void voteMinus(const int postId);
            Q_INVOKABLE void voteNeutral(const int postId);
            Q_INVOKABLE void votePlus(const int postId);

            enum VoteType{VOTE_MINUS = -1, VOTE_NEUTRAL, VOTE_PLUS};

        private:
            void vote(const int postId, PostResource::VoteType voteType);

        private:
            Q_DISABLE_COPY(PostResource)
        };
    }
}

#endif
