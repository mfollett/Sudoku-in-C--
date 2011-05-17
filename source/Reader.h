#include <fstream>
#include <string>
#include <exception>
using std::ifstream;
using std::string;

#include <iostream>;
using std::cout;
using std::endl;

class Reader
{
    public:
        Reader(std::string filename) : stream(filename.c_str())
        {
            refill_iterator();
        }
        char next();

    private:

        void refill_iterator()
        {
            stream >> buffer;
            cout << "Got new buffer: " << buffer << endl;
            buffer_iterator = buffer.begin();
        }

        ifstream          stream;
        string            buffer;
        string::iterator  buffer_iterator;


};