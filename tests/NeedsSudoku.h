#ifndef _NEEDSSUDOKU_
#define _NEEDSSUDOKU_
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class NeedsSudoku : public CppUnit::TestCase
{
    public:
        void setUp()
        {
            const short size = 9;
            vector<shorts> rows(0);

            short proto_board[][size] = {
                { 1, 2, 3, 4, 5, 6, 7, 8, 9},
                { 1, 2, 2, 2, 2, 2, 2, 2, 2},
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

    protected:
        Sudoku *board;
};
#endif
