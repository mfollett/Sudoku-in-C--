#ifndef _SPACE_
#define _SPACE_

#include <vector>

#include "Sudoku.h"
#include "Line.h"
#include "types.h"

class Space
{
    public:
        Space(const Sudoku board, short i, short j)
            : vertical( board, i ), horizontal( board, j ), square( board, i, j)
        {
        }

        shorts possible_values()
        {
            shorts values(Sudoku::POSSIBLE_VALUE_COUNT, 0); // number of possible values plus blank
            values[Sudoku::BLANK]++; // blank is never an option
            populate_values( vertical, values);
            populate_values( horizontal, values);
            populate_values_from_square( values );
            return extract_nonzero_values( values );
        }

    private:
        const Line<line::VERTICAL> vertical;
        const Line<line::HORIZONTAL> horizontal;
        const SubBoard square;

        template <line::direction T>
        void populate_values( Line<T> line, shorts &values )
        {
            shorts::iterator i = line.begin();
            do
            {
                values[*i]++;
            }while( ++i != line.end() );
        }

        void populate_values_from_square( shorts &values )
        {
            for( int i = 0; i < square.SIZE; i++ )
            {
                for( int j = 0; j < square.SIZE; j++ )
                {
                    values[square.get(i,j)]++;
                }
            }
        }

        shorts extract_nonzero_values(const shorts &values )
        {
            shorts retval(0);
            for( int i = 0; Sudoku::POSSIBLE_VALUE_COUNT > i; i++ )
            {
                if( 0 == values[i] )
                {
                    retval.push_back(i);
                }
            }
            return retval;
        }
};

#endif
