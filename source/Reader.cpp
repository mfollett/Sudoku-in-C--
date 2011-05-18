#include "Reader.h"

char Reader::next()
{
    if( !( stream.is_open() && stream.good() ) )
    {
        throw new std::exception();
    }
    do
    {
        while( buffer_iterator < buffer.end() )
        {
            char c = *buffer_iterator;
            buffer_iterator++;
            if( '_' == c || ( '0' < c && '9' >= c ))
            {
                return c;
            }
        }
        refill_iterator();
    }while( ! stream.eof() );
    return END;
}

