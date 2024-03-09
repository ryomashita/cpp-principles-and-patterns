#ifndef SRC_TYPEERASURE_BASE_SPECIFICDRAWSTRATEGY_H
#define SRC_TYPEERASURE_BASE_SPECIFICDRAWSTRATEGY_H

#include <numbers>

#include "Circle.h"
#include "Square.h"
/* include Specific Libraries */

namespace typeerasure {
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
}  // namespace typeerasure

#endif  // SRC_TYPEERASURE_BASE_SPECIFICDRAWSTRATEGY_H
