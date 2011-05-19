#include <vector>
using std::vector;

#include <cppunit/extensions/HelperMacros.h>

#include "types.h"
#include "NeedsSudoku.h"

#include <iostream>
using namespace std;

class LineTest : public NeedsSudoku
{
    CPPUNIT_TEST_SUITE(LineTest);
    CPPUNIT_TEST(testVertical);
    CPPUNIT_TEST(testHorizontal);
    CPPUNIT_TEST_SUITE_END();

    public:

        void testVertical()
        {
            for( int column = 0; 9 > column; column++ )
            {
                Line<line::VERTICAL> line = Line<line::VERTICAL>(*board, column);

                shorts::iterator iter = line.begin();
                for(unsigned short i = 0; 9 > i; i++ )
                {
                    CPPUNIT_ASSERT( column+1 == *iter ); iter++;
                }
                CPPUNIT_ASSERT( iter == line.end() );
            }
        }


        void testHorizontal()
        {
            Line<line::HORIZONTAL> line = Line<line::HORIZONTAL>(*board, 0);

            shorts::iterator iter = line.begin();
            for(short i = 1; 10 > i; i++ )
            {
                CPPUNIT_ASSERT( i == *iter ); iter++;
            }
            CPPUNIT_ASSERT( iter == line.end() );
        }
            
};


