#include <gtest/gtest.h>

#include <array>
#include <numeric>

#include "Circle.h"
#include "Shape.h"
#include "SpecificDrawStrategy.h"
#include "Square.h"
#include "StoragePolicy.h"

using namespace typeerasure;

TEST(TypeErasureOptShapeTest, CircleDraw) {
  Circle circle(3.0);
  // Strategy は operator(Circle const & circle) を持つなら、
  // 構造体でもフリー関数でもラムダでもよい
  Shape<InClassStorage<>> shape(circle, SpecificDrawStrategy{});
  ASSERT_DOUBLE_EQ(draw(shape), 3.0 * 3.0 * std::numbers::pi);
}

TEST(TypeErasureOptShapeTest, CopiedCircleDraw) {
  Circle circle(3.0);
  Shape<InClassStorage<>> shape(circle, SpecificDrawStrategy{});
  Shape copied_shape = shape;  // deep copy (call Shape copy constructor)
  ASSERT_DOUBLE_EQ(draw(copied_shape), 3.0 * 3.0 * std::numbers::pi);
}

TEST(TypeErasureOptShapeTest, SquareDraw) {
  Square square(3.0);
  Shape<InClassStorage<>> shape(square, SpecificDrawStrategy{});
  ASSERT_DOUBLE_EQ(draw(shape), 3.0 * 3.0);

  Shape copied_shape = shape;
  ASSERT_DOUBLE_EQ(draw(copied_shape), 3.0 * 3.0);
}

TEST(TypeErasureOptShapeTest, AllShapeDraw) {
  using Shapes = std::array<Shape<InClassStorage<>>, 2>;
  Shapes shapes{
      Shape<InClassStorage<>>(Circle{3.0}, SpecificDrawStrategy{}),
      Shape<InClassStorage<>>(Square{3.0}, SpecificDrawStrategy{}),
  };
  double ret = std::accumulate(
      shapes.begin(), shapes.end(), 0.0,
      [](double acc, auto const& shape) { return acc + draw(shape); });
  EXPECT_FLOAT_EQ(ret, 3.0 * 3.0 * std::numbers::pi + 3.0 * 3.0);
}