#include "DrawSquare.h"

#include "Square.h"

namespace visitor {

double GetArea(Square const& square) { return square.side() * square.side(); }

}  // namespace visitor