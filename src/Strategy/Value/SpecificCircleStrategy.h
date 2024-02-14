#ifndef SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H
#define SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H

#include <numbers>

#include "Circle.h"
/* include Specific Libraries */

namespace strategy {
class SpecificCircleStrategy {
 public:
  SpecificCircleStrategy() = default;

  double operator()(Circle const& circle) const {
    return std::numbers::pi * circle.radius() * circle.radius();
  }
};
}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H
