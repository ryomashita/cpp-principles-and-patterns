#ifndef SRC_STRATEGY_AFTER_SQUARE_H
#define SRC_STRATEGY_AFTER_SQUARE_H

#include <memory>
#include <utility>

#include "DrawStrategy.h"
#include "Shape.h"

namespace strategy {
class Square : public Shape {
 public:
  Square(double rad, std::unique_ptr<DrawStrategy<Square>> strategy)
      : side_(rad), drawer_(std::move(strategy)) {}

  double Draw() const override { return drawer_->draw(*this); }

  double side() const { return side_; }

 private:
  double side_;
  std::unique_ptr<DrawStrategy<Square>> drawer_;
};

}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_SQUARE_H
