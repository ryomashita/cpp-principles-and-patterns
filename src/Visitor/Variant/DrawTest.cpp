#include <gtest/gtest.h>

#include "Circle.h"
#include "Draw.h"
#include "DrawAllShapes.h"
#include "Shape.h"
#include "Square.h"

using namespace visitor;

TEST(DrawTest, Circle_Draw) {
  Circle circle(5);
  EXPECT_FLOAT_EQ(Draw{}(circle), 78.53981633974483);
}

TEST(DrawTest, Square_Draw) {
  Square square(5);
  EXPECT_FLOAT_EQ(Draw{}(square), 25);
}

TEST(DrawTest, DrawAllShapes) {
  Shapes shapes;
  shapes.emplace_back(Circle(5));
  shapes.emplace_back(Square(5));
  EXPECT_FLOAT_EQ(drawAllShapes(shapes), 103.53981633974483);
}
