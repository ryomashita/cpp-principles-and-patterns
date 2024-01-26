#include <gtest/gtest.h>

#include <numeric>
#include <vector>

#include "Range.h"

using namespace FreeFunction;

TEST(RangeTest, traverseRange) {
  std::vector<int> v{1, 2, 3, 4, 5};
  int accum = 0;
  traverseRange(v, [&accum](auto& i) { accum += i; });
  EXPECT_EQ(accum, std::reduce(v.begin(), v.end()));
}

TEST(RangeTest, traverseRange_CArray) {
  int arr[]{1, 2, 3, 4, 5};
  int accum = 0;
  traverseRange(arr, [&accum](auto& i) { accum += i; });
  EXPECT_EQ(accum, std::reduce(std::cbegin(arr), std::cend(arr)));
}