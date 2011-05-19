#ifndef _SPACE_
#define _SPACE_

#include <vector>

#include "types.h"


class Space
{
    public:
        Space(const Sudoku board, short i, short j)
            : vertical( board, j ), horizontal( board, i ),
              square( board, i, j), _i(i), _j(j), got_possible_values(false)
        { }

        Space(const Space &s)
            : vertical(s.vertical), horizontal(s.horizontal), square(s.square),
              _i(s._i), _j(s._j) {}

        Space() : vertical(), horizontal(), square(), _i(0), _j(0) {}

        shorts possible_values()
        {
            if(!got_possible_values)
            {
                shorts values(Sudoku::POSSIBLE_VALUE_COUNT, 0); // number of possible values plus blank
                values[Sudoku::BLANK]++; // blank is never an option
                populate_values( vertical, values);
                populate_values( horizontal, values);
                populate_values_from_square( values );
                cached_possible_values = extract_nonzero_values( values );
            }
            return cached_possible_values;
        }

        static bool sort_by_restrictions( Space a, Space b )
        {
            return a.possible_values().size() < b.possible_values().size();
        }

        unsigned short i() const { return _i; }
        unsigned short j() const { return _j; }

    private:
        VerticalLine vertical;
        HorizontalLine horizontal;
        SubBoard square;
        unsigned short _i;
        unsigned short _j;
        bool  got_possible_values;
        shorts cached_possible_values;

        template <line::direction T>
        void populate_values( Line<T> line, shorts &values )
        {
            shorts::iterator i = line.begin();
            while( i != line.end() )
            {
                values[*i]++;
                i++;
            }
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
