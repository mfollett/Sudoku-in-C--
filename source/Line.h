#ifndef _LINE_
#define _LINE_
#include "Sudoku.h"
#include "types.h"

namespace line
{
    enum direction { VERTICAL, HORIZONTAL };
}

template <line::direction T>
class Line
{
    public:
        Line<T>( const Sudoku &board, short i )
        {
            for( short j = 0; board.SIZE > j; j++ )
            {
                switch(T)
                {
                    case line::HORIZONTAL:
                        store.push_back( board.get(i,j) );
                        break;
                    case line::VERTICAL:
                        store.push_back( board.get(j,i) );
                        break;
                }
            }

        }

        int size() const
        {
            return store.size();
        }

        shorts::iterator begin()
        {
            return store.begin();
        }

        shorts::iterator end()
        {
            return store.end();
        }

    private:
        shorts store;
};
#endif
