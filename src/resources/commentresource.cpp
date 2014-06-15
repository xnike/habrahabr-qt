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

#include "include/resources/commentresource.hpp"

namespace habrahabr {
    namespace resources {
        CommentResource::CommentResource(AbstractAdapter* adapter, QObject* parent) : AbstractResource(adapter, parent) {
        }

        AbstractEntity* CommentResource::getCommentsForPost(const int postId) {
            return adapter->doGet(QString("/comments/%1").arg(postId));
        }

        AbstractEntity* CommentResource::postComment(const int postId, const QString text, const int parentCommentId) {
            QVariantMap data;
            data["parentCommentId"] = parentCommentId;
            data["text"] = text;
            return adapter->doPut(QString("/comments/%1").arg(postId), data);
        }

        void CommentResource::vote(const int commentId, CommentResource::VoteType voteType) {
            QVariantMap data;
            data["vote"] = voteType;
            adapter->doPut(QString("/comments/%1/vote").arg(commentId), data);
        }

        void CommentResource::voteMinus(const int commentId) {
            vote(commentId, CommentResource::VOTE_MINUS);
        }

        void CommentResource::votePlus(const int commentId) {
            vote(commentId, CommentResource::VOTE_PLUS);
        }
    }
}
