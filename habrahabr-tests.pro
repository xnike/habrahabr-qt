# Copyright (c) 2014 Nikolay Khramchenkov (xnike.me@gmail.com).
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

include(habrahabr.pro)

QT       += testlib

TARGET = habrahabr-tests
TEMPLATE = app
DEFINES -= HABRAHABR_LIBRARY

SOURCES +=  tests/main.cpp \
    tests/adapters/mockadapter.cpp \
    tests/backend/mockbackend.cpp \
    tests/backend/requesthandler.cpp \
    tests/backend/rule.cpp \
    tests/searchresourcetest.cpp \
    tests/syncadaptertest.cpp

HEADERS += tests/adapters/mockadapter.hpp \
    tests/autotest.hpp \
    tests/backend/mockbackend.hpp \
    tests/backend/requesthandler.hpp \
    tests/backend/rule.hpp \
    tests/searchresourcetest.hpp \
    tests/syncadaptertest.hpp
