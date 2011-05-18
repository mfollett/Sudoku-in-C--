#include <cppunit/ui/text/TestRunner.h>

#include "ReaderTest.h"
#include "LineTest.h"

int main()
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( ReaderTest::suite() );
  runner.addTest( LineTest::suite() );
  runner.run();
  return 0;
}
