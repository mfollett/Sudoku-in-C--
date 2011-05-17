#include <cppunit/ui/text/TestRunner.h>

#include "ReaderTest.h"

int main()
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( ReaderTest::suite() );
  runner.run();
  return 0;
}
