#ifndef SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H
#define SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H

#include "Circle.h"
#include "DrawStrategy.h"
/* include Specific Libraries */

namespace strategy {
class SpecificCircleStrategy : public DrawStrategy<Circle> {
 public:
  SpecificCircleStrategy() = default;
  virtual ~SpecificCircleStrategy() = default;
  double draw(Circle const& circle) const override {
    return std::numbers::pi * circle.radius() * circle.radius();
  }
};
}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_SPECIFICCIRCLESTRATEGY_H
