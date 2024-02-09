#ifndef SRC_VISITOR_VARIANT_DRAW_H
#define SRC_VISITOR_VARIANT_DRAW_H

#include <numbers>

#include "Circle.h"
#include "Square.h"

// Visitor Pattern with std::variant :
// 汎用的な処理の追加を抽象化するデザインパターン。
// 処理の追加は容易だが、型の追加は容易ではない（全てのVisitorを変更する必要がある）
//
// Procedural approachからの変更点：
// 仮想関数のオーバーライドではなく、関数オブジェクトを使用
//   => 処理を全ての型で個別に実装する必要がない。 &　戻り値も型ごとに変更できる

namespace visitor {
struct Draw {
  double operator()(const Circle& circle) const {
    return std::numbers::pi * circle.radius() * circle.radius();
  }

  double operator()(const Square& square) const {
    return square.side() * square.side();
  }
};

}  // namespace visitor

#endif  // SRC_VISITOR_VARIANT_DRAW_H
