#include <string>
using std::string;

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Reader.h"

class ReaderTest : public CppUnit::TestCase
{
    CPPUNIT_TEST_SUITE(ReaderTest);
    CPPUNIT_TEST(testNext);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testNext();

        void setUp()
        {
            reader = new Reader("./tests/example/reader1.txt");
        }

        void tearDown()
        {
            delete reader;
        }

    private:
        Reader *reader;
};

