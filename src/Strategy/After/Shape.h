#ifndef SRC_STRATEGY_AFTER_SHAPE_H
#define SRC_STRATEGY_AFTER_SHAPE_H

namespace strategy {
class Shape {
 public:
  Shape() = default;
  virtual ~Shape() = default;
  virtual double Draw() const = 0;
};
}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_SHAPE_H
