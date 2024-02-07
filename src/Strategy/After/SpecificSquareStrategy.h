#ifndef SRC_STRATEGY_AFTER_SPECIFICSQUARESTRATEGY_H
#define SRC_STRATEGY_AFTER_SPECIFICSQUARESTRATEGY_H

#include "DrawStrategy.h"
#include "Square.h"

namespace strategy {
class SpecificSquareStrategy : public DrawStrategy<Square> {
 public:
  SpecificSquareStrategy() = default;
  virtual ~SpecificSquareStrategy() = default;
  double draw(Square const& square) const override {
    return square.side() * square.side();
  }
};
}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_SPECIFICSQUARESTRATEGY_H
