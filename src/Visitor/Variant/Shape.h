#ifndef SRC_VISITOR_VARIANT_SHAPE_H
#define SRC_VISITOR_VARIANT_SHAPE_H

#include <variant>

#include "Circle.h"
#include "Square.h"

// Procedural approachからの変更点：
// 1. 基底クラスではなくなり、逆に具象クラスを参照する側になる
// 2. std::variantを使用

namespace visitor {
using Shape = std::variant<Circle, Square>;
}  // namespace visitor

#endif  // SRC_VISITOR_VARIANT_SHAPE_H
