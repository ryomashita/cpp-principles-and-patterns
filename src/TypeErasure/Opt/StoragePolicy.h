#ifndef SRC_TYPEERASURE_OPT_STORAGEPOLICY_H
#define SRC_TYPEERASURE_OPT_STORAGEPOLICY_H

#include <cstddef>
#include <memory>
#include <utility>
namespace typeerasure {

struct DynamicStorage {
  template <typename T, typename... Args>
  T* create(Args&&... args) const {
    return new T(std::forward<Args>(args)...);
  }

  template <typename T>
  void destroy(T* ptr) const {
    delete ptr;
  }
};

template <size_t Capacity = 32U, size_t Alignment = alignof(void*)>
struct InClassStorage {
  template <typename T, typename... Args>
  T* create(Args&&... args) const {
    static_assert(sizeof(T) <= Capacity, "Given type is too large");
    static_assert(alignof(T) <= Alignment, "Given type is misaligned");

    // construct_at(Location, Args...):
    // Locationメモリ領域にコンストラクタを呼び出す
    T* memory = const_cast<T*>(reinterpret_cast<T const*>(buffer_.data()));
    return std::construct_at(memory, std::forward<Args>(args)...);
  }

  template <typename T>
  void destroy(T* ptr) const {
    std::destroy_at(ptr);
  }

  alignas(Alignment) std::array<std::byte, Capacity> buffer_;
};

}  // namespace typeerasure

#endif  // SRC_TYPEERASURE_OPT_STORAGEPOLICY_H
