#ifndef SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H
#define SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H

#include <numbers>

#include "Circle.h"
#include "Square.h"
/* include Specific Libraries */

namespace extpoly {
class SpecificDrawStrategy {
 public:
  explicit SpecificDrawStrategy() = default;

  double operator()(Circle const& circle) const {
    return std::numbers::pi * circle.radius() * circle.radius();
  }

  double operator()(Square const& square) const {
    return square.side() * square.side();
  }
};
}  // namespace extpoly

#endif  // SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H
