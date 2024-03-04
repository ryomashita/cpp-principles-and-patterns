#ifndef SRC_PROTOTYPE_ANIMALS_H
#define SRC_PROTOTYPE_ANIMALS_H

#include "Animal.h"

namespace prototype {

class Sheep : public Animal {
 public:
  explicit Sheep(std::string name) : name_(std::move(name)) {}
  std::string makeSound() const override { return name_ + "baa"; }
  std::unique_ptr<Animal> clone() const override {
    // make_unique でコピーを生成できる
    return std::make_unique<Sheep>(*this);
  }

 private:
  std::string name_;
};

class Cat : public Animal {
 public:
  explicit Cat(std::string name) : name_(std::move(name)) {}
  std::string makeSound() const override { return name_ + "meow"; }
  std::unique_ptr<Animal> clone() const override {
    return std::make_unique<Cat>(*this);
  }

 private:
  std::string name_;
};

}  // namespace prototype

#endif  // SRC_PROTOTYPE_ANIMALS_H
