#ifndef SRC_EXTERNALPOLYMORPHISM_CIRCLE_H
#define SRC_EXTERNALPOLYMORPHISM_CIRCLE_H

namespace extpoly {
class Circle {
 public:
  explicit Circle(double rad) : radius_(rad) {}

  double radius() const { return radius_; }

 private:
  double radius_;
};

}  // namespace extpoly

#endif  // SRC_EXTERNALPOLYMORPHISM_CIRCLE_H
