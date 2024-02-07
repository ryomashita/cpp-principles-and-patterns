#ifndef SRC_STRATEGY_AFTER_DRAWSTRATEGY_H
#define SRC_STRATEGY_AFTER_DRAWSTRATEGY_H

namespace strategy {
template <typename T>
class DrawStrategy {
 public:
  virtual ~DrawStrategy() = default;
  virtual double draw(T const& shape) const = 0;
};

}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_DRAWSTRATEGY_H
