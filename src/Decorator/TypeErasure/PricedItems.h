#ifndef SRC_DECORATOR_TEMPLATE_PRICEDITEMS_H
#define SRC_DECORATOR_TEMPLATE_PRICEDITEMS_H
#include "Money.h"

// Decorator Pattern (using Template) :
// サブクラスを定義することで、既存の型の振る舞いの一部を変更する古典的パターン。
// C++20 では Concept を用いることで、継承関係なしに型をグループ化できる。

// テンプレートによるコンパイル時抽象化は極めて高速な一方、
// 実行時の柔軟性が全くないため、使用場面を選ぶ。

#include <utility>

#include "Item.h"

namespace decorator {

class Discounted {
 public:
  Discounted(double discount, Item item)
      : item_{std::move(item)}, factor_{1.0 - discount} {}

  Money price() const { return item_.price() * factor_; }

 private:
  Item item_;
  double factor_;
};

class Taxed {
 public:
  Taxed(double taxRate, Item item)
      : item_{std::move(item)}, factor_{1.0 + taxRate} {}

  Money price() const { return item_.price() * factor_; }

 private:
  Item item_;
  double factor_;
};

}  // namespace decorator

#endif  // SRC_DECORATOR_TEMPLATE_PRICEDITEMS_H
