#include <vector>
using std::vector;

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Line.h"
#include "Sudoku.h"
#include "types.h"

class LineTest : public CppUnit::TestCase
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
            for(short i = 0; 9 > i; i++ )
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
            
        void setUp()
        {
            const short size = 9;
            vector<shorts> rows(0);

            short proto_board[][size] = {
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9}
            };

            for( short i = 0; i < size; i++ )
            {
                shorts row(0);
                for( short j = 0; j < size; j++ )
                {
                    row.push_back(proto_board[i][j]);
                }
                rows.push_back(row);
            }

            board = new Sudoku(rows);
        }

        void tearDown()
        {
            delete board;
        }

    private:
        Sudoku *board;
};


