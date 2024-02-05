#ifndef SHAPES_H
#define SHAPES_H

#include <vector>

#include "Shape.h"

// Procedural approachからの変更点：
// 1. ポインタではなく、std::variantで複数具象クラスを参照する

namespace visitor {
using Shapes = std::vector<Shape>;
}

#endif  // SHAPES_H
