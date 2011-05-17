#include "ReaderTest.h"

void ReaderTest::testNext()
{
    char answers[] = {'1','2','3','_', '4','5','6'};

    int i = 0;
    while( char pigeonhole = reader->next() )
    {
        CPPUNIT_ASSERT( pigeonhole == answers[i++] );
    }
}
