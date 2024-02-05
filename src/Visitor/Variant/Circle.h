#ifndef SRC_VISITOR_VARIANT_CIRCLE_H
#define SRC_VISITOR_VARIANT_CIRCLE_H

#include "Point.h"

// Procedural approachからの変更点：
// 1. Shapeクラスの継承を削除
// 2. ShapeTypeの参照を削除

namespace visitor {
class Circle {
 public:
  Circle(double radius) : radius_(radius) {}
  ~Circle() = default;

  Point center() const { return center_; }
  double radius() const { return radius_; }

 private:
  Point center_{};
  double radius_;
};

}  // namespace visitor

#endif  // SRC_VISITOR_VARIANT_CIRCLE_H
