#ifndef SRC_CRTP_BEFORE_DYNAMICVECTOR_H
#define SRC_CRTP_BEFORE_DYNAMICVECTOR_H

#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// Before : without CRTP Pattern
// DynamicVector と StaticVector はほぼ同じ実装を持ち、コードが重複している

namespace crtp {
template <typename T>
class DynamicVector {
 public:
  using value_type = T;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  DynamicVector() = default;
  ~DynamicVector() = default;
  DynamicVector(std::initializer_list<T> il) : value_{std::move(il)} {}
  DynamicVector(DynamicVector const&) = default;
  DynamicVector(DynamicVector&&) = default;
  DynamicVector& operator=(DynamicVector const&) = default;
  DynamicVector& operator=(DynamicVector&&) = default;

  size_t size() const { return value_.size(); }

  T& operator[](size_t index) { return value_[index]; }
  const T& operator[](size_t index) const { return value_[index]; }

  iterator begin() { return value_.begin(); }
  const_iterator begin() const { return value_.begin(); }
  iterator end() { return value_.end(); }
  const_iterator end() const { return value_.end(); }

 private:
  std::vector<T> value_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, DynamicVector<T> const& vecctor) {
  os << "(";
  for (auto const& element : vecctor) {
    os << " " << element;
  }
  os << " )";

  return os;
}

template <typename T>
auto l2norm(DynamicVector<T> const& vector) {
  using std::begin, std::end;
  return std::sqrt(
      std::inner_product(begin(vector), end(vector), begin(vector), T{}));
}

}  // namespace crtp

#endif  // SRC_CRTP_BEFORE_DYNAMICVECTOR_H
