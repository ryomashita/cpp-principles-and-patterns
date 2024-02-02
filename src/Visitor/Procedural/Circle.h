#ifndef SRC_VISITOR_PROCEDURAL_CIRCLE_H
#define SRC_VISITOR_PROCEDURAL_CIRCLE_H

#include "Point.h"
#include "Shape.h"

namespace visitor {

class Circle : public Shape {
 public:
  explicit Circle(double radius) : Shape(ShapeType::circle), radius_(radius) {}

  double radius() const { return radius_; }
  Point center() const { return center_; }

 private:
  double radius_;
  Point center_{};
};

}  // namespace visitor

#endif  // SRC_VISITOR_PROCEDURAL_CIRCLE_H
