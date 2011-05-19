#ifndef _SUDOKU_
#define _SUDOKU_
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <assert.h>

#include "types.h"
#include "Reader.h"

template <int T>
class Board
{
    public:
        static const unsigned short BLANK = 0;
        static const unsigned short POSSIBLE_VALUE_COUNT = 10;
        const unsigned short SIZE;
        Board( std::string board_file_name) : SIZE(T)
        {
            build_board(board_file_name);
        }

        Board( std::vector<shorts> b ) : SIZE(T), board(b)
        {
            assert( SIZE == board.size() );
            std::vector<shorts>::iterator iter = board.begin();
            while( board.end() != iter )
            {
                assert( SIZE == iter->size() );
                iter++;
            }
        }


        template <int S>
        Board( Board<S> big_board, unsigned short i, unsigned short j ) : SIZE(T)
        {
            unsigned short i_sector = i/SIZE;
            unsigned short j_sector = j/SIZE;
            for( unsigned short subspace_i = 0; subspace_i < SIZE; subspace_i++ )
            {
                shorts line;
                for( unsigned short subspace_j = 0; subspace_j < SIZE; subspace_j++ )
                {
                    line.push_back(big_board.get(i_sector * SIZE + subspace_i, j_sector * SIZE + subspace_j));
                }
                board.push_back(line);
            }
        }

        char get(unsigned short i, unsigned short j) const
        {
            return board[i][j];
        }

    private:
        std::vector<shorts> board;

        void build_board(std::string board_file_name)
        {
            Reader reader(board_file_name);
            unsigned short i = 0, j = 0;
            while( char c = reader.next() )
            {

                if( SIZE == j )
                {
                    j = 0;
                    i++;
                }
                if( '_' == c )
                {
                    board[i][j] = BLANK;
                }
                else
                {
                    board[i][j] = boost::lexical_cast<unsigned short>(c);
                }
                j++;
            }
        }
};

typedef Board<9> Sudoku;
typedef Board<3> SubBoard;

#endif
