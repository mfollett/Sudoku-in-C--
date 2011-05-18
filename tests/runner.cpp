#include <cppunit/ui/text/TestRunner.h>

#include "ReaderTest.h"
#include "LineTest.h"
#include "SpaceTest.h"

int main()
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( ReaderTest::suite() );
  runner.addTest( LineTest::suite() );
  runner.addTest( SpaceTest::suite() );
  runner.run();
  return 0;
}
