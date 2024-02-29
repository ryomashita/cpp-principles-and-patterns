#include <gtest/gtest.h>

#include "StrongType.h"

using namespace strongtype;

template <typename T>
using Meter = StrongType<T, struct MeterTag, Addable, Printable, Swappable>;

template <typename T>
using Kilometer =
    StrongType<T, struct KilometerTag, Addable, Printable, Swappable>;

template <typename T>
using Surname = StrongType<T, struct SurnameTag, Printable, Swappable>;

TEST(StrongTypeTest, CreateStrongType) {
  // Constructor
  Meter<int> meter(5);
  Kilometer<int> kilometer(5);
  Surname<std::string> surname("Doe");

  ASSERT_EQ(5, meter.get());
  ASSERT_EQ(5, kilometer.get());
  ASSERT_EQ("Doe", surname.get());

  // using Skills
  Meter<int> meter2 = meter + meter;
  Surname<std::string> surname2("John");
  std::swap(surname, surname2);

  ASSERT_EQ(10, meter2.get());
  ASSERT_EQ("John", surname.get());
}