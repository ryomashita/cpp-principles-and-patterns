#include <gtest/gtest.h>

#include "Add.h"
#include "Calculator.h"
#include "Subtract.h"
// #include <cstdlib>

using namespace command;

TEST(CalculatorValueTest, Add) {
  Calculator calc;
  calc.compute(Add(5).command_set());
  EXPECT_EQ(5, calc.result());
  calc.compute(Add(10).command_set());
  EXPECT_EQ(15, calc.result());
  calc.undoLast();
  EXPECT_EQ(5, calc.result());
  calc.undoLast();
  EXPECT_EQ(0, calc.result());
}

TEST(CalculatorValueTest, Subtract) {
  Calculator calc;
  calc.compute(Subtract(5).command_set());
  EXPECT_EQ(-5, calc.result());
  calc.compute(Subtract(10).command_set());
  EXPECT_EQ(-15, calc.result());
  calc.undoLast();
  EXPECT_EQ(-5, calc.result());
  calc.undoLast();
  EXPECT_EQ(0, calc.result());
}

TEST(CalculatorValueTest, AddAndSubtract) {
  Calculator calc;
  calc.compute(Add(5).command_set());
  EXPECT_EQ(5, calc.result());
  calc.compute(Subtract(10).command_set());
  EXPECT_EQ(-5, calc.result());
  calc.undoLast();
  EXPECT_EQ(5, calc.result());
  calc.undoLast();
  EXPECT_EQ(0, calc.result());
}