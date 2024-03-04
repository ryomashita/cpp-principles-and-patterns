#include <gtest/gtest.h>

#include <memory>

#include "Animal.h"
#include "Animals.h"

using namespace prototype;

TEST(PrototypeTest, CreateSheep) {
  Sheep sheep("Dolly");
  std::unique_ptr<Animal> sheep2 = sheep.clone();
  ASSERT_EQ("Dollybaa", sheep2->makeSound());
}

TEST(PrototypeTest, CreateCat) {
  Cat cat("Tom");
  std::unique_ptr<Animal> cat2 = cat.clone();
  ASSERT_EQ("Tommeow", cat2->makeSound());
}