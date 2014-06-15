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

#include "include/resources/userresource.hpp"

namespace habrahabr {
    namespace resources {
        UserResource::UserResource(AbstractAdapter* adapter, QObject* parent) : AbstractResource(adapter, parent) {
        }

        AbstractEntity* UserResource::getUser(const QString login){
            return adapter->doGet(QString("/users/%1").arg(login));
        }

        AbstractEntity* UserResource::getUserComments(const QString login, const int page) {
            return adapter->doGet(QString("/users/%1/comments?page=%2").arg(login).arg(page));
        }

        AbstractEntity* UserResource::getUserCompanies(const QString login) {
            return adapter->doGet(QString("/users/%1/companies").arg(login));
        }

        AbstractEntity* UserResource::getUserCurrent() {
            return getUser("me");
        }

        AbstractEntity* UserResource::getUserFavoritesComments(const QString login, const int page) {
            return adapter->doGet(QString("/users/%1/favorites/comments?page=%2").arg(login).arg(page));
        }

        AbstractEntity* UserResource::getUserFavoritesPost(const QString login, const int page) {
            return adapter->doGet(QString("/users/%1/favorites/posts?page=%2").arg(login).arg(page));
        }

        AbstractEntity* UserResource::getUserFollowed(const QString login, const int page) {
            return adapter->doGet(QString("/users/%1/followed?page=%2").arg(login).arg(page));
        }

        AbstractEntity* UserResource::getUserFollowers(const QString login, const int page) {
            return adapter->doGet(QString("/users/%1/followers?page=%2").arg(login).arg(page));
        }

        AbstractEntity* UserResource::getUserHubs(const QString login) {
            return adapter->doGet(QString("/users/%1/hubs").arg(login));
        }

        AbstractEntity* UserResource::getUserPosts(const QString login, const int page) {
            return adapter->doGet(QString("/users/%1/posts?page=%2").arg(login).arg(page));
        }

        AbstractEntity* UserResource::getUsersList() {
            return adapter->doGet("/users");
        }

        void UserResource::voteKarmaMinus(const QString target) {
            adapter->doDelete(QString("/users/%1/vote").arg(target));
        }

        void UserResource::voteKarmaPlus(const QString target) {
            adapter->doPut(QString("/users/%1/vote").arg(target), QVariantMap());
        }
    }
}
