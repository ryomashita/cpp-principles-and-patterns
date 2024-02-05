#ifndef SRC_VISITOR_VARIANT_SQUARE_H
#define SRC_VISITOR_VARIANT_SQUARE_H

#include "Point.h"

// Procedural approachからの変更点：
// 1. Shapeクラスの継承を削除
// 2. ShapeTypeの参照を削除

namespace visitor {
class Square {
 public:
  Square(double side) : side_(side) {}
  ~Square() = default;

  Point center() const { return center_; }
  double side() const { return side_; }

 private:
  Point center_{};
  double side_;
};

}  // namespace visitor

#endif  // SRC_VISITOR_VARIANT_SQUARE_H
