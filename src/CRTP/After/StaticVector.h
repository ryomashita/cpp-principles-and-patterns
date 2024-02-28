#ifndef SRC_CRTP_BEFORE_STATICVECTOR_H
#define SRC_CRTP_BEFORE_STATICVECTOR_H

#include <array>
#include <cstddef>

#include "DenseVector.h"

namespace crtp {

template <typename T, size_t Size>
struct StaticVector {
 public:
  using value_type = T;
  using iterator = typename std::array<T, Size>::iterator;
  using const_iterator = typename std::array<T, Size>::const_iterator;

  // https://cpprefjp.github.io/reference/array/array/op_initializer.html
  // std::array は コンストラクタ を持たず、
  // 組み込み配列と同様の初期化構文で初期化する。
  // public な固定長配列メンバを持つ。

  size_t size() const { return value_.size(); }

  T& operator[](size_t index) { return value_[index]; }
  const T& operator[](size_t index) const { return value_[index]; }

  iterator begin() { return value_.begin(); }
  const_iterator begin() const { return value_.begin(); }
  iterator end() { return value_.end(); }
  const_iterator end() const { return value_.end(); }

 public:
  std::array<T, Size> value_;
};

// IsDenseVector 型特性(concept) は特殊化が可能
template <typename T, size_t Size>
struct IsDenseVector<StaticVector<T, Size>> : public std::true_type {};

}  // namespace crtp

#endif  // SRC_CRTP_BEFORE_STATICVECTOR_H
