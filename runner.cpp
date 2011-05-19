#include "types.h"
#include <iostream>
#include <vector>
using std::cout; using std::endl;
int main()
{

    const short size = 9;
    short proto_board[][size] = {
        { 7, 8, 2, 6, 1, 0/*5*/, 9, 3, 4},
        { 1, 4, 3, 7, 0/*9*/, 2, 8, 5, 6},
        { 9, 5, 6, 8, 4, 3, 7, 1, 0/*2*/},
        { 8, 6, 0/*1*/, 5, 2, 7, 3, 4, 9},
        { 2, 3, 5, 9, 6, 4, 1, 0/*8*/, 7},
        { 4, 0/*7*/, 9, 3, 8, 1, 6, 2, 5},
        { 5, 1, 8, 0/*2*/, 7, 9, 4, 6, 3},
        { 0/*6*/, 2, 7, 4, 3, 0/*8*/, 5, 9, 1},
        { 3, 9, 4, 0/*1*/, 5, 6, 2, 7, 8}
    };

    std::vector< shorts > rows;
    for( short i = 0; i < size; i++ )
    {
        shorts row(0);
        for( short j = 0; j < size; j++ )
        {
            row.push_back(proto_board[i][j]);
        }
        rows.push_back(row);
    }

    Sudoku board(rows);
    Sudoku solution = Solver::solve(board);

    for( int i = 0; i < solution.SIZE; i++ )
    {
        if( i % 3 == 0 )
        {
            cout << endl;
        }
        for( int j = 0; j < solution.SIZE; j++ )
        {
            if( j % 3 == 0 )
            {
                cout << '|';
            }
            cout << static_cast<int>(solution.get(i,j));
        }
        cout << endl;
    }
}
