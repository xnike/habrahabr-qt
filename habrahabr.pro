# Copyright (c) 2014 Nikolay Khramchenkov <xnike.me@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

QT       += network
QT       -= gui

TARGET = habrahabr
TEMPLATE = lib

DEFINES += HABRAHABR_LIBRARY
INCLUDEPATH += include

HEADERS += include/habrahabr_global.hpp \
    include/client.hpp \
    include/adapters/abstractadapter.hpp \
    include/adapters/syncadapter.hpp \
    include/entities/abstractentity.hpp \
    include/resources/abstractresource.hpp \
    include/resources/commentresource.hpp \
    include/resources/companyresource.hpp \
    include/resources/feedresource.hpp \
    include/resources/hubresource.hpp \
    include/resources/postresource.hpp \
    include/resources/searchresource.hpp \
    include/resources/trackerresource.hpp \
    include/resources/userresource.hpp
SOURCES += src/client.cpp \
    src/adapters/abstractadapter.cpp \
    src/adapters/syncadapter.cpp \
    src/entities/abstractentity.cpp \
    src/resources/abstractresource.cpp \
    src/resources/commentresource.cpp \
    src/resources/companyresource.cpp \
    src/resources/feedresource.cpp \
    src/resources/hubresource.cpp \
    src/resources/postresource.cpp \
    src/resources/searchresource.cpp \
    src/resources/trackerresource.cpp \
    src/resources/userresource.cpp

# TODO usage private classes
# TODO async & sync usage of methods
    
unix {
    target.path = /usr/lib
    INSTALLS += target
}
