#include <gtest/gtest.h>

#include "Widget.h"

using namespace HowToTestPrivateMethod;

TEST(BlobCollectionTest, updateCollection) {
  std::set<Blob> blobs{1, 2, 3, 4, 5};
  BlobCollection blobCollection(blobs);
  EXPECT_EQ(blobCollection.updateCollection(blobs), 5);
}