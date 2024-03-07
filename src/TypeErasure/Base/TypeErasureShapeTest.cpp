#include <gtest/gtest.h>

#include <memory>
#include <numeric>
#include <vector>

#include "Circle.h"
#include "Shape.h"
#include "SpecificDrawStrategy.h"
#include "Square.h"

using namespace typeerasure;

TEST(TypeErasureShapeTest, CircleDraw) {
  Circle circle(3.0);
  // Strategy は operator(Circle const & circle) を持つなら、
  // 構造体でもフリー関数でもラムダでもよい
  Shape shape(circle, SpecificDrawStrategy{});
  ASSERT_DOUBLE_EQ(draw(shape), 3.0 * 3.0 * std::numbers::pi);
}

TEST(TypeErasureShapeTest, CopiedCircleDraw) {
  Circle circle(3.0);
  Shape shape(circle, SpecificDrawStrategy{});
  Shape copied_shape = shape;  // deep copy (call Shape copy constructor)
  ASSERT_DOUBLE_EQ(draw(copied_shape), 3.0 * 3.0 * std::numbers::pi);
}

TEST(TypeErasureShapeTest, SquareDraw) {
  Square square(3.0);
  Shape shape(square, SpecificDrawStrategy{});
  ASSERT_DOUBLE_EQ(draw(shape), 3.0 * 3.0);

  Shape copied_shape = shape;
  ASSERT_DOUBLE_EQ(draw(copied_shape), 3.0 * 3.0);
}

TEST(TypeErasureShapeTest, AllShapeDraw) {
  using Shapes = std::vector<std::unique_ptr<Shape>>;
  Shapes shapes{};
  shapes.emplace_back(
      std::make_unique<Shape>(Circle{3.0}, SpecificDrawStrategy{}));
  shapes.emplace_back(
      std::make_unique<Shape>(Square{3.0}, SpecificDrawStrategy{}));
  double ret = std::accumulate(
      shapes.begin(), shapes.end(), 0.0,
      [](double acc, auto const& shape) { return acc + draw(*shape); });
  EXPECT_FLOAT_EQ(ret, 3.0 * 3.0 * std::numbers::pi + 3.0 * 3.0);
}