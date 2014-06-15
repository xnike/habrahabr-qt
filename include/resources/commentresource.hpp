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

#ifndef COMMENTRESOURCE_HPP
#define COMMENTRESOURCE_HPP

#include "abstractresource.hpp"

namespace habrahabr {
    namespace resources {
        class CommentResource : public AbstractResource {
            Q_OBJECT

        public:
            explicit CommentResource(AbstractAdapter* adapter, QObject* parent = 0);

            Q_INVOKABLE AbstractEntity* getCommentsForPost(const int postId);
            Q_INVOKABLE AbstractEntity* postComment(const int postId, const QString text, const int parentCommentId = 0);
            Q_INVOKABLE void voteMinus(const int commentId);
            Q_INVOKABLE void votePlus(const int commentId);

            enum VoteType{VOTE_MINUS = -1, VOTE_PLUS = 1};

        private:
            void vote(const int commentId, CommentResource::VoteType voteType);

        private:
            Q_DISABLE_COPY(CommentResource)
        };
    }
}

#endif
