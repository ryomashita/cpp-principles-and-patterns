#include <gtest/gtest.h>

#include "Circle.h"
#include "DrawAllShapes.h"
#include "DrawCircle.h"
#include "DrawSquare.h"
#include "Square.h"

using namespace visitor;

TEST(DrawTest, Circle_GetArea) {
  Circle circle(5);
  EXPECT_FLOAT_EQ(GetArea(circle), 78.53981633974483);
}

TEST(DrawTest, Square_GetArea) {
  Square square(5);
  EXPECT_FLOAT_EQ(GetArea(square), 25);
}

TEST(DrawTest, GetAllArea) {
  std::vector<std::shared_ptr<Shape>> shapes;
  shapes.emplace_back(std::make_shared<Circle>(5));
  shapes.emplace_back(std::make_shared<Square>(5));
  EXPECT_FLOAT_EQ(GetAllArea(shapes), 103.53981633974483);
}