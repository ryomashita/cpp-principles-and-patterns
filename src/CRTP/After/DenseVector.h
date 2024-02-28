#ifndef SRC_CRTP_AFTER_DENSEVECTOR_H
#define SRC_CRTP_AFTER_DENSEVECTOR_H

#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <type_traits>

// After : CRTP Pattern with C++20 Concepts
// 重複する処理 operator<<, l2norm を DenseVector 型特性 (concept) に実装する。
// 意図しない型を受け付けないように、 空の構造体 DenseVectorTag でタグ付けする。
// サブクラスでは、共通処理に必要なプロパティのみ実装すればよい。

namespace crtp {
struct DenseVectorTag {};

// bool is_base_of_v = is_base_of<Base, Derived>::value;
// Base が Derived の基底クラスである場合に true を返す

template <typename T>
struct IsDenseVector : public std::is_base_of<DenseVectorTag, T> {};

template <typename T>
constexpr bool IsDenseVector_v = IsDenseVector<T>::value;

// requires 節を使って、T の要件を記述 & 実装する
template <typename T>
concept DenseVector = requires(T t, size_t index) {
  t.size();  // size() メンバ関数がある、という要件
  t[index];
  // begin() がiterator を返す
  { t.begin() } -> std::same_as<typename T::iterator>;
  { t.end() } -> std::same_as<typename T::iterator>;
} && requires(T const t, size_t index) {
  t[index];
  { t.begin() } -> std::same_as<typename T::const_iterator>;
  { t.end() } -> std::same_as<typename T::const_iterator>;
} && IsDenseVector_v<T>;
// other requirements for DenseVector is here

// 共通処理をフリー関数で実装する
// 受け入れる型を 型特性 (concept) で制限する
template <DenseVector VectorT>
std::ostream& operator<<(std::ostream& os, VectorT const& vector) {
  os << "(";
  for (auto const& element : vector) {
    os << " " << element;
  }
  os << " )";

  return os;
}

template <DenseVector VectorT>
auto l2norm(VectorT const& vector) {
  using std::begin, std::end;
  return std::sqrt(std::inner_product(begin(vector), end(vector), begin(vector),
                                      typename VectorT::value_type{}));
}

}  // namespace crtp

#endif  // SRC_CRTP_AFTER_DENSEVECTOR_H
