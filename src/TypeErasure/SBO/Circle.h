#ifndef SRC_TYPEERASURE_BASE_CIRCLE_H
#define SRC_TYPEERASURE_BASE_CIRCLE_H

namespace typeerasure {
class Circle {
 public:
  explicit Circle(double rad) : radius_(rad) {}

  double radius() const { return radius_; }

 private:
  double radius_;
};

}  // namespace typeerasure

#endif  // SRC_TYPEERASURE_BASE_CIRCLE_H
