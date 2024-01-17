#include <gtest/gtest.h>

#include "Widget_Before.h"

namespace HowToTestPrivateMethod {

class WidgetTestFriend : public ::testing::Test {
 protected:
  WidgetTestFriend() : widget_(std::set<Blob>{1, 2, 3}) {}
  ~WidgetTestFriend() = default;

  virtual void SetUp() {}
  virtual void TearDown() {}

  Widget widget_;
  auto updateCollection(std::set<Blob> blobs) {
    return widget_.updateCollection(blobs);
  }
};

TEST_F(WidgetTestFriend, updateCollection) {
  std::set<Blob> blobs{1, 2, 3, 4, 5};
  EXPECT_EQ(updateCollection(blobs), 5);
}

}  // namespace HowToTestPrivateMethod