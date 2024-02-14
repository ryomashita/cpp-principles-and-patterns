#ifndef SRC_STRATEGY_AFTER_CIRCLE_H
#define SRC_STRATEGY_AFTER_CIRCLE_H

#include <functional>
#include <utility>

#include "Shape.h"

// Strategy Pattern (Value Semantics Based):
// 依存オブジェクト(DrawStrategy)を型ではなくstd::functionとして受け取る。
// これによりStrategy基底型は不要になり、ただ関数型の一致するoperator()を持つだけでよくなる。
//
// 参照セマンティクスではなく、値セマンティクスを使うことで、
// コードが簡潔になり、ライフタイムの管理を気にせずに済むようになる。

namespace strategy {
class Circle : public Shape {
 public:
  using DrawStrategy = std::function<double(Circle const&)>;

  // DrawStrategy は const& ではなく 値渡し にする。
  // std::functionはコピー/ムーブコンストラクタの両方を持つため、下手にconst&を使わずコンパイラに任せる
  // (ちゃんとした原理は書籍p.179参照)
  Circle(double rad, DrawStrategy strategy)
      : radius_(rad), drawer_(std::move(strategy)) {}

  double Draw() const override { return drawer_(*this); }

  double radius() const { return radius_; }

 private:
  double radius_;
  DrawStrategy drawer_;
};

}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_CIRCLE_H
