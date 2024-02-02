#include "DrawAllShapes.h"

#include "Circle.h"
#include "DrawCircle.h"
#include "DrawSquare.h"
#include "Square.h"

namespace visitor {
double GetAllArea(std::vector<std::shared_ptr<Shape>> const& shapes) {
  double accum = 0;
  for (auto const& shape : shapes) {
    switch (shape->getType()) {
      case ShapeType::circle:
        accum += GetArea(static_cast<Circle const&>(*shape));
        break;
      case ShapeType::square:
        accum += GetArea(static_cast<Square const&>(*shape));
        break;
      default:
        break;
    }
  }
  return accum;
}

}  // namespace visitor