#ifndef SRC_CRTP_BEFORE_DYNAMICVECTOR_H
#define SRC_CRTP_BEFORE_DYNAMICVECTOR_H

#include <cstddef>
#include <initializer_list>
#include <vector>

#include "DenseVector.h"

namespace crtp {
template <typename T>
class DynamicVector : private DenseVectorTag {
 public:
  using value_type = T;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  DynamicVector() = default;
  DynamicVector(std::initializer_list<T> il) : value_{std::move(il)} {}

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

}  // namespace crtp

#endif  // SRC_CRTP_BEFORE_DYNAMICVECTOR_H
