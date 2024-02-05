#ifndef SRC_VISITOR_VARIANT_DRAW_H
#define SRC_VISITOR_VARIANT_DRAW_H

#include <numbers>

#include "Shape.h"

// Procedural approachからの変更点：
// 1. 仮想関数のオーバーライドではなく、関数オブジェクトを使用
//   => 全ての具象クラスで実装する必要はなくなる。 & 戻り値も型ごとに変更できる

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
