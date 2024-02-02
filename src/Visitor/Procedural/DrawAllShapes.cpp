#include "DrawAllShapes.h"

#include "Circle.h"
#include "DrawCircle.h"
#include "DrawSquare.h"
#include "Square.h"

// Visitor Before (Procedural approach)
// 列挙型ShareTypeによりShapreサブクラスを判別する。
// 新たなShareサブクラス(ShareType)を追加するたび、switch文を修正する必要があり、
// 実質的に保守不可能といえる。
// 主たる原因は、全ての型と処理が列挙型に直接依存し、結びついている点にある。

namespace visitor {
double GetAllArea(std::vector<std::shared_ptr<Shape>> const& shapes) {
  double accum = 0;
  for (auto const& shape : shapes) {
    switch (shape->getType()) {
      case ShapeType::circle:
        accum += GetArea(static_cast<Circle const&>(*shape));
        break;
      case ShapeType::square:
        accum += GetArea(static_cast<Square const&>(*shape));
        break;
      default:
        break;
    }
  }
  return accum;
}

}  // namespace visitor