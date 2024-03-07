#include <gtest/gtest.h>

#include <memory>
#include <numeric>
#include <vector>

#include "Circle.h"
#include "Shape.h"
#include "SpecificDrawStrategy.h"
#include "Square.h"

using namespace extpoly;

TEST(ExtPolyShapeTest, CircleDraw) {
  using CircleModel = ShapeModel<Circle, SpecificDrawStrategy>;
  CircleModel circle(Circle{5}, SpecificDrawStrategy());
  EXPECT_FLOAT_EQ(circle.draw(), 78.53981633974483);
}

TEST(ExtPolyShapeTest, SquareDraw) {
  using SquareModel = ShapeModel<Square, SpecificDrawStrategy>;
  SquareModel square(Square{5}, SpecificDrawStrategy());
  EXPECT_FLOAT_EQ(square.draw(), 25);
}

TEST(ExtPolyShapeTest, AllShapeDraw) {
  using Shapes = std::vector<std::unique_ptr<ShapeConcept>>;
  using CircleModel = ShapeModel<Circle, SpecificDrawStrategy>;
  using SquareModel = ShapeModel<Square, SpecificDrawStrategy>;

  Shapes shapes{};
  shapes.emplace_back(
      std::make_unique<CircleModel>(Circle{5}, SpecificDrawStrategy()));
  shapes.emplace_back(
      std::make_unique<SquareModel>(Square{5}, SpecificDrawStrategy()));

  double ret = std::accumulate(
      shapes.begin(), shapes.end(), 0.0,
      [](double acc, auto const& shape) { return acc + shape->draw(); });
  EXPECT_FLOAT_EQ(ret, 103.53981633974483);
}