#ifndef _TYPES_
#define _TYPES_
#include <vector>

typedef std::vector<unsigned short> shorts;

namespace line
{
    enum direction { VERTICAL, HORIZONTAL };
}

template <line::direction T>
class Line;
typedef Line<line::VERTICAL> VerticalLine;
typedef Line<line::HORIZONTAL> HorizontalLine;

class Space;
typedef std::vector<Space> spaces;

template <int T>
class Board;

typedef Board<9> Sudoku;
typedef Board<3> SubBoard;
// not super happy about this, will clean up later @TODO
#include <Reader.h>
#include <Sudoku.h>
#include <Line.h>
#include <Space.h>
#include <Solver.h>
#endif
