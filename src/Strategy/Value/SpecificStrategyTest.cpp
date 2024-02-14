#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include "Circle.h"
#include "Shape.h"
#include "SpecificCircleStrategy.h"
#include "SpecificSquareStrategy.h"
#include "Square.h"

using namespace strategy;

TEST(StrategyValueTest, CircleDraw) {
  Circle circle(5, SpecificCircleStrategy());
  EXPECT_FLOAT_EQ(circle.Draw(), 78.53981633974483);
}

TEST(StrategyValueTest, SquareDraw) {
  Square square(5, SpecificSquareStrategy());
  EXPECT_FLOAT_EQ(square.Draw(), 25);
}

TEST(StrategyValueTest, AllShapeDraw) {
  using Shapes = std::vector<std::unique_ptr<Shape>>;
  Shapes shapes{};
  shapes.emplace_back(std::make_unique<Circle>(5, SpecificCircleStrategy()));
  shapes.emplace_back(std::make_unique<Square>(5, SpecificSquareStrategy()));
  double sum = 0;
  for (const auto& shape : shapes) {
    sum += shape->Draw();
  }
  EXPECT_FLOAT_EQ(sum, 103.53981633974483);
}