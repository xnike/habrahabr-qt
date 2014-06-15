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

#ifndef USERRESOURCE_HPP
#define USERRESOURCE_HPP

#include "abstractresource.hpp"

namespace habrahabr {
    namespace resources {
        class UserResource : public AbstractResource {
            Q_OBJECT

        public:
            explicit UserResource(AbstractAdapter* adapter, QObject* parent = 0);

            Q_INVOKABLE AbstractEntity* getUser(const QString login);
            Q_INVOKABLE AbstractEntity* getUserComments(const QString login, const int page = 1);
            Q_INVOKABLE AbstractEntity* getUserCompanies(const QString login);
            Q_INVOKABLE AbstractEntity* getUserCurrent();
            Q_INVOKABLE AbstractEntity* getUserFavoritesComments(const QString login, const int page = 1);
            Q_INVOKABLE AbstractEntity* getUserFavoritesPost(const QString login, const int page = 1);
            Q_INVOKABLE AbstractEntity* getUserFollowed(const QString login, const int page = 1);
            Q_INVOKABLE AbstractEntity* getUserFollowers(const QString login, const int page = 1);
            Q_INVOKABLE AbstractEntity* getUserHubs(const QString login);
            Q_INVOKABLE AbstractEntity* getUserPosts(const QString login, const int page = 1);
            Q_INVOKABLE AbstractEntity* getUsersList();
            /* Ask for permissions at http://habrahabr.ru/feedback/ */
            Q_INVOKABLE void voteKarmaMinus(QString target);
            /* Ask for permissions at http://habrahabr.ru/feedback/ */
            Q_INVOKABLE void voteKarmaPlus(QString target);

        private:
            Q_DISABLE_COPY(UserResource)
        };
    }
}

#endif
