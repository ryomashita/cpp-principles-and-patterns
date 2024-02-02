#include "DrawCircle.h"

#include <numbers>

#include "Circle.h"

namespace visitor {
double GetArea(Circle const& circle) {
  return std::numbers::pi * circle.radius() * circle.radius();
}
}  // namespace visitor