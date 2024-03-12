#ifndef SRC_DECORATOR_TEMPLATE_PRICEDITEMS_H
#define SRC_DECORATOR_TEMPLATE_PRICEDITEMS_H
#include "Money.h"

// Decorator Pattern (using Template) :
// サブクラスを定義することで、既存の型の振る舞いの一部を変更する古典的パターン。
// C++20 では Concept を用いることで、継承関係なしに型をグループ化できる。

// テンプレートによるコンパイル時抽象化は極めて高速な一方、
// 実行時の柔軟性が全くないため、使用場面を選ぶ。

namespace decorator {

// Concept を用いることで、継承関係なしに型をグループ化できる
template <typename T>
concept PricedItem = requires(T item) {
  { item.price() } -> std::same_as<Money>;
};

// Item を所有し、price() の振る舞いだけを変更する
template <double discount, PricedItem Item>
class Discounted {
 public:
  template <typename... Args>
  explicit Discounted(Args&&... args) : item_{std::forward<Args>(args)...} {}

  Money price() const { return item_.price() * (1.0 - discount); }

 private:
  Item item_;
};

// コンポジションの代わりに継承を利用することもできる
template <double taxRate, PricedItem Item>
class Taxed : private Item {
 public:
  template <typename... Args>
  explicit Taxed(Args&&... args) : Item{std::forward<Args>(args)...} {}

  Money price() const { return Item::price() * (1.0 + taxRate); };
};

}  // namespace decorator

#endif  // SRC_DECORATOR_TEMPLATE_PRICEDITEMS_H
