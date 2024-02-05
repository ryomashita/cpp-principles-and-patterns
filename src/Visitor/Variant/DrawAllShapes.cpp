#include "DrawAllShapes.h"

#include "Draw.h"

// Procedural approachからの変更点：
// 1. もはやswitch文を使用せず、std::visitで自動的にディスパッチされる

namespace visitor {
double drawAllShapes(Shapes const& shapes) {
  double accum = 0;
  for (auto const& shape : shapes) {
    // std::visit(Visitor, Variants...)
    // variantが実行時に保持する型に従い、ディスパッチされた関数オブジェクトを呼び出す。
    // Visitor: Variantsに対応するオーバーロードを持つ関数オブジェクト
    // Variants...: std::variantのインスタンス
    accum += std::visit(Draw{}, shape);
  }
  return accum;
}
}  // namespace visitor
