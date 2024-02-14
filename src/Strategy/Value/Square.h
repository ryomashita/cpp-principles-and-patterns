#ifndef SRC_STRATEGY_AFTER_SQUARE_H
#define SRC_STRATEGY_AFTER_SQUARE_H

#include <functional>
#include <utility>

#include "Shape.h"

namespace strategy {
class Square : public Shape {
 public:
  using DrawStrategy = std::function<double(Square const&)>;

  Square(double rad, DrawStrategy strategy)
      : side_(rad), drawer_(std::move(strategy)) {}

  double Draw() const override { return drawer_(*this); }

  double side() const { return side_; }

 private:
  double side_;
  DrawStrategy drawer_;
};

}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_SQUARE_H
