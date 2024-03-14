#include <gtest/gtest.h>
#include "PersistenceInterface.h"

  using namespace singleton;

TEST(SingletonTest, Default)
{
  auto persistence = get_persistence_instance();
  ASSERT_EQ(persistence, global_persistence);
}

TEST(SingletonTest, ReadWrite)
{
  PersistenceInterface* persistence = get_persistence_instance();
  uint64_t data = 0x1122;
  ASSERT_TRUE(persistence->read(0, data));
  ASSERT_EQ(data, 0);
  ASSERT_TRUE(persistence->write(0, 1));
  ASSERT_TRUE(persistence->read(0, data));
  ASSERT_EQ(data, 1);
}