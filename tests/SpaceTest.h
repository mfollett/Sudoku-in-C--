#include <vector>
using std::vector;

#include <cppunit/extensions/HelperMacros.h>

#include "Space.h"
#include "types.h"
#include "NeedsSudoku.h"

class SpaceTest : public NeedsSudoku
{
    CPPUNIT_TEST_SUITE(SpaceTest);
    CPPUNIT_TEST(testPossibleValues);
    CPPUNIT_TEST_SUITE_END();

    public:
    void testPossibleValues()
    {
        Space sp1 = Space( *board, 0, 0);
        CPPUNIT_ASSERT( 0 == sp1.possible_values().size() );

        Space sp2 = Space( *board, 1, 1);
        shorts values = sp2.possible_values();
        CPPUNIT_ASSERT( 6 == values.size() );
        for( int i = 4; i <= 9; i++ )
        {
            CPPUNIT_ASSERT( values[i-4] == i );
        }
    }
};
