#ifndef SRC_STRATEGY_AFTER_SPECIFICSQUARESTRATEGY_H
#define SRC_STRATEGY_AFTER_SPECIFICSQUARESTRATEGY_H

#include "Square.h"

namespace strategy {
class SpecificSquareStrategy {
 public:
  SpecificSquareStrategy() = default;

  double operator()(Square const& square) const {
    return square.side() * square.side();
  }
};
}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_SPECIFICSQUARESTRATEGY_H
