#ifndef SRC_DECORATOR_TYPEERASURE_ITEM_H
#define SRC_DECORATOR_TYPEERASURE_ITEM_H

#include <memory>
#include <utility>

#include "Money.h"

// Decorator Pattern (using Type Erasure) :
// Type Erasure パターンを使用することで、動的に Decorator クラスを生成できる。
// 要件(price()とコピーコンストラクタ)を満たせばItemは任意の型でよく、
// そのため 直接継承関係のない ConferenceTicket も扱える。

namespace decorator {

class Item {
 public:
  template <typename T>
  Item(T item) : pimpl_{std::make_unique<Model<T>>(std::move(item))} {}

  Item(Item const& other) : pimpl_{other.pimpl_->clone()} {}
  Item& operator=(Item const& other) {
    pimpl_ = other.pimpl_->clone();
    return *this;
  }
  ~Item() = default;
  Item(Item&&) = default;
  Item& operator=(Item&&) = default;

  Money price() const { return pimpl_->price(); }

 private:
  struct Concept {
    virtual ~Concept() = default;
    virtual Money price() const = 0;
    virtual std::unique_ptr<Concept> clone() const = 0;
  };

  template <typename T>
  struct Model : public Concept {
    explicit Model(T const& item) : item_{item} {}
    explicit Model(T&& item) : item_{std::move(item)} {}
    Money price() const override { return item_.price(); }
    std::unique_ptr<Concept> clone() const override {
      return std::make_unique<Model<T>>(item_);
    }
    T item_;
  };

  std::unique_ptr<Concept> pimpl_;
};

}  // namespace decorator

#endif  // SRC_DECORATOR_TYPEERASURE_ITEM_H
