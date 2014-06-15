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

#ifndef AUTOTEST_HPP
#define AUTOTEST_HPP

#include <QList>
#include <QString>
#include <QSharedPointer>
#include <QTest>

namespace AutoTest {
    typedef QList<QObject*> TestList;
    
    inline TestList& testList() {
        static TestList list;
        return list;
    }

    inline bool findObject(QObject* object) {
        TestList& list = testList();
	
        if (list.contains(object)) {
            return true;
        }

        foreach (QObject* test, list) {
            if (test->objectName() == object->objectName()) {
                return true;
            }
        }

        return false;
    }
    
    inline void addTest(QObject* object) {
        TestList& list = testList();

        if (!findObject(object)) {
            list.append(object);
        }
    }
    
    inline int run(int argc, char *argv[]) {
        int ret = 0;
	
        foreach (QObject* test, testList()) {
            ret += QTest::qExec(test, argc, argv);
        }
	
        return ret;
    }
}

template <class T>
class Test {
public:
    QSharedPointer<T> child;
    
    Test(const QString& name): child(new T) {
        child->setObjectName(name);
        AutoTest::addTest(child.data());
    }
};

#define DECLARE_TEST(className) static Test<className> t(#className);

#define TEST_MAIN \
int main(int argc, char *argv[]) { \
    QCoreApplication app(argc, argv); \
    return AutoTest::run(argc, argv); \
}

#endif
