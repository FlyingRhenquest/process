#include <cppunit/extensions/HelperMacros.h>
#include "process.hpp"

/**
    * Copyright 2014 Bruce Ide
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

class process_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(process_test);
  CPPUNIT_TEST(basic_test);
  CPPUNIT_TEST_SUITE_END();

public:

  void basic_test()
  {
    fr::process hiworld("/bin/echo hello world!");
    hiworld.start();      
    hiworld.join(); // Wait for completion

    std::string result;
    getline(hiworld.out->stream_in, result);
    std::string expected("hello world!");
    CPPUNIT_ASSERT(expected == result);
  }

};

CPPUNIT_TEST_SUITE_REGISTRATION(process_test);
