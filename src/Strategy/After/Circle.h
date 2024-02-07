#ifndef SRC_STRATEGY_AFTER_CIRCLE_H
#define SRC_STRATEGY_AFTER_CIRCLE_H

#include <memory>
#include <utility>

#include "DrawStrategy.h"
#include "Shape.h"

// Strategy Pattern:
// 単一の処理を抽象化(DrawStrategy)し、依存オブジェクトとして注入する。
// これにより型の追加が容易になる。
// 一方で処理の追加は困難で、既存の型全てを変更し、コンストラクタ引数を増やす必要がある。
// 従って「処理の追加が少なく」「型の追加が多い」と予想されるケースで有効。

namespace strategy {
class Circle : public Shape {
 public:
  Circle(double rad, std::unique_ptr<DrawStrategy<Circle>> strategy)
      : radius_(rad), drawer_(std::move(strategy)) {}

  double Draw() const override { return drawer_->draw(*this); }

  double radius() const { return radius_; }

 private:
  double radius_;
  std::unique_ptr<DrawStrategy<Circle>> drawer_;
};

}  // namespace strategy

#endif  // SRC_STRATEGY_AFTER_CIRCLE_H
