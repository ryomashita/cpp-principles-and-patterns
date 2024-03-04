#ifndef SRC_PROTOTYPE_ANIMAL_H
#define SRC_PROTOTYPE_ANIMAL_H

#include <memory>
#include <string>

// Prototype Pattern :
// 基底クラスに clone()
// 仮想メソッドを実装することで、サブクラスのコピーを生成できる。
// 参照セマンティクスを用いる限り、Prototype
// パターンを置き換えるモダンな方法はない。
// 値セマンティクスへの移行も併せて検討すること。

namespace prototype {

class Animal {
 public:
  virtual ~Animal() = default;
  virtual std::string makeSound() const = 0;
  virtual std::unique_ptr<Animal> clone() const = 0;
};

}  // namespace prototype

#endif  // SRC_PROTOTYPE_ANIMAL_H
