#ifndef SRC_EXTERNALPOLYMORPHISM_CIRCLE_H
#define SRC_EXTERNALPOLYMORPHISM_CIRCLE_H

// Strategy Pattern (Value Semantics Based):
// 依存オブジェクト(DrawStrategy)を型ではなくstd::functionとして受け取る。
// これによりStrategy基底型は不要になり、ただ関数型の一致するoperator()を持つだけでよくなる。
//
// 参照セマンティクスではなく、値セマンティクスを使うことで、
// コードが簡潔になり、ライフタイムの管理を気にせずに済むようになる。

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
