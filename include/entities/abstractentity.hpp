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

#ifndef ABSTRACTENTITY_HPP
#define ABSTRACTENTITY_HPP

#include <QObject>

namespace habrahabr {
    namespace entities {
        class AbstractEntity : public QObject {
            Q_OBJECT

        public:
            explicit AbstractEntity(QObject* parent = 0);
            explicit AbstractEntity(QString value, QObject* parent = 0);

            Q_INVOKABLE QString getValue();
            Q_INVOKABLE bool isValid();

        private:
            QString value;
            bool valid;
        };
    }
}

#endif
