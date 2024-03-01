#include <gtest/gtest.h>

#include "Person.h"

using namespace pimpl;

TEST(PimplTest, CreatePerson) {
  Person person;
  ASSERT_EQ(0, person.year_of_birth());
}

TEST(PimplTest, CopyPerson) {
  Person person;
  person.set_year_of_birth(30);
  Person person2 = person;
  ASSERT_EQ(30, person2.year_of_birth());
}