#include <gtest/gtest.h>

#include "DenseVector.h"
#include "DynamicVector.h"
#include "StaticVector.h"

using namespace crtp;

TEST(DynamicVectorTest, L2Norm) {
  DynamicVector<double> vector{3, 4};
  EXPECT_DOUBLE_EQ(5.0, l2norm(vector));
  std::cout << vector << std::endl;
}

TEST(StaticVectorTest, L2Norm) {
  StaticVector<double, 2> vector{3, 4};
  EXPECT_DOUBLE_EQ(5.0, l2norm(vector));
  std::cout << vector << std::endl;
}