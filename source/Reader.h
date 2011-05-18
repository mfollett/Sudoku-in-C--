#ifndef _READER_
#define _READER_
#include <fstream>
#include <string>
#include <exception>
using std::ifstream;
using std::string;

class Reader
{
    public:
        static const char END = 0;
        Reader(std::string filename) : stream(filename.c_str())
        {
            refill_iterator();
        }
        char next();

    private:

        void refill_iterator()
        {
            stream >> buffer;
            buffer_iterator = buffer.begin();
        }

        ifstream          stream;
        string            buffer;
        string::iterator  buffer_iterator;


};
#endif
