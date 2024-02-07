#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include "Circle.h"
#include "SpecificCircleStrategy.h"
#include "SpecificSquareStrategy.h"
#include "Square.h"

using namespace strategy;

TEST(StrategyTest, CircleDraw) {
  std::unique_ptr<DrawStrategy<Circle>> strategy =
      std::make_unique<SpecificCircleStrategy>();
  Circle circle(5, std::move(strategy));
  EXPECT_FLOAT_EQ(circle.Draw(), 78.53981633974483);
}

TEST(StrategyTest, SquareDraw) {
  std::unique_ptr<DrawStrategy<Square>> strategy =
      std::make_unique<SpecificSquareStrategy>();
  Square square(5, std::move(strategy));
  EXPECT_FLOAT_EQ(square.Draw(), 25);
}

TEST(StrategyTest, AllShapeDraw) {
  std::vector<std::unique_ptr<Shape>> shapes;
  std::unique_ptr<DrawStrategy<Circle>> circle_strategy =
      std::make_unique<SpecificCircleStrategy>();
  shapes.emplace_back(std::make_unique<Circle>(5, std::move(circle_strategy)));
  std::unique_ptr<DrawStrategy<Square>> square_strategy =
      std::make_unique<SpecificSquareStrategy>();
  shapes.emplace_back(std::make_unique<Square>(5, std::move(square_strategy)));
  double sum = 0;
  for (const auto& shape : shapes) {
    sum += shape->Draw();
  }
  EXPECT_FLOAT_EQ(sum, 103.53981633974483);
}