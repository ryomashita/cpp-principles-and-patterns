#ifndef SRC_TYPEERASURE_BASE_SQUARE_H
#define SRC_TYPEERASURE_BASE_SQUARE_H

namespace typeerasure {
class Square {
 public:
  Square(double rad) : side_(rad) {}

  double side() const { return side_; }

 private:
  double side_;
};

}  // namespace typeerasure

#endif  // SRC_TYPEERASURE_BASE_SQUARE_H
