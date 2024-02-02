#ifndef SRC_VISITOR_PROCEDURAL_SQUARE_H
#define SRC_VISITOR_PROCEDURAL_SQUARE_H

#include "Point.h"
#include "Shape.h"

namespace visitor {
class Square : public Shape {
 public:
  explicit Square(double side) : Shape(ShapeType::square), side_(side) {}

  double side() const { return side_; }
  Point center() const { return center_; }

 private:
  double side_;
  Point center_{};
};
}  // namespace visitor

#endif  // SRC_VISITOR_PROCEDURAL_SQUARE_H
