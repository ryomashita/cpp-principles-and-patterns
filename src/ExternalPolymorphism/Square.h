#ifndef SRC_STRATEGY_AFTER_SQUARE_H
#define SRC_STRATEGY_AFTER_SQUARE_H

namespace extpoly {
class Square {
 public:
  Square(double rad) : side_(rad) {}

  double side() const { return side_; }

 private:
  double side_;
};

}  // namespace extpoly

#endif  // SRC_STRATEGY_AFTER_SQUARE_H
