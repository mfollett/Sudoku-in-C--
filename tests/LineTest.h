#include <vector>
using std::vector;

#include <cppunit/extensions/HelperMacros.h>

#include "Line.h"
#include "Sudoku.h"
#include "types.h"
#include "NeedsSudoku.h"

class LineTest : public NeedsSudoku
{
    CPPUNIT_TEST_SUITE(LineTest);
    CPPUNIT_TEST(testHorizontal);
    CPPUNIT_TEST(testVertical);
    CPPUNIT_TEST_SUITE_END();

    public:

        void testVertical()
        {
            Line<line::VERTICAL> line = Line<line::VERTICAL>(*board, 0);

            shorts::iterator iter = line.begin();
            for(unsigned short i = 0; 9 > i; i++ )
            {
                CPPUNIT_ASSERT( 1 == *iter ); iter++;
            }
            CPPUNIT_ASSERT( iter == line.end() );
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


