#include <gtest/gtest.h>

#include "Add.h"
#include "Calculator.h"
#include "Subtract.h"
// #include <cstdlib>

using namespace command;

TEST(CalculatorTest, Add) {
  Calculator calc;
  calc.compute(std::make_unique<Add>(5));
  EXPECT_EQ(5, calc.result());
  calc.compute(std::make_unique<Add>(10));
  EXPECT_EQ(15, calc.result());
  calc.undoLast();
  EXPECT_EQ(5, calc.result());
  calc.undoLast();
  EXPECT_EQ(0, calc.result());
}

TEST(CalculatorTest, Subtract) {
  Calculator calc;
  calc.compute(std::make_unique<Subtract>(5));
  EXPECT_EQ(-5, calc.result());
  calc.compute(std::make_unique<Subtract>(10));
  EXPECT_EQ(-15, calc.result());
  calc.undoLast();
  EXPECT_EQ(-5, calc.result());
  calc.undoLast();
  EXPECT_EQ(0, calc.result());
}

TEST(CalculatorTest, AddAndSubtract) {
  Calculator calc;
  calc.compute(std::make_unique<Add>(5));
  EXPECT_EQ(5, calc.result());
  calc.compute(std::make_unique<Subtract>(10));
  EXPECT_EQ(-5, calc.result());
  calc.undoLast();
  EXPECT_EQ(5, calc.result());
  calc.undoLast();
  EXPECT_EQ(0, calc.result());
}