#ifndef SRC_STRONGTYPE_STRONGTYPE_H
#define SRC_STRONGTYPE_STRONGTYPE_H

#include <iostream>
#include <utility>

// StrongType :
// 組み込み型をラップすることで、異なる型どうしの誤った演算を防げる。
// (CRTPを用いた静的Mixinクラスの実装) :
// 基底クラスが サブクラス (StrongType) を型引数にとることで、
// 基底クラスからサブクラスの具象実装メンバーに、静的にアクセスできる。
// 仮想関数コールはないため、実行時オーバーヘッドがない。

namespace strongtype {

template <typename T, typename Tag, template <typename> class... Skills>
struct StrongType : private Skills<StrongType<T, Tag, Skills...>>... {
 public:
  using value_type = T;

  explicit StrongType(T const& value) : value_(value) {}

  T& get() { return value_; }
  T const& get() const { return value_; }

 private:
  T value_;
};

// friend 関数：
// クラスメンバーではないが、引数の型のプライベートメンバにアクセスできる。

template <typename Derived>
struct Addable {
  friend Derived& operator+=(Derived& lhs, Derived const& rhs) {
    lhs.get() += rhs.get();
    return lhs;
  }

  friend Derived operator+(Derived const& lhs, Derived const& rhs) {
    return Derived(lhs.get() + rhs.get());
  }
};

template <typename Derived>
struct Printable {
  friend std::ostream& operator<<(std::ostream& os, Derived const& value) {
    return os << value.get();
  }
};

template <typename Derived>
struct Swappable {
  friend void swap(Derived& lhs, Derived& rhs) {
    using std::swap;
    swap(lhs.get(), rhs.get());
  }
};

}  // namespace strongtype

#endif  // SRC_STRONGTYPE_STRONGTYPE_H
