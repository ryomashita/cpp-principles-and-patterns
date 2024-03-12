#ifndef SRC_DECORATOR_TEMPLATE_MONEY_H
#define SRC_DECORATOR_TEMPLATE_MONEY_H

#include <ostream>
#include <type_traits>

namespace decorator {

struct Money {
  double value{};
};

bool operator==(Money lhs, Money rhs) { return lhs.value == rhs.value; }

template <typename T>
  requires std::is_arithmetic_v<T>
Money operator*(Money money, T factor) {
  return Money{static_cast<double>(money.value * factor)};
}

constexpr Money operator+(Money lhs, Money rhs) noexcept {
  return Money{lhs.value + rhs.value};
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
  return os << money.value;
}

}  // namespace decorator

#endif  // SRC_DECORATOR_TEMPLATE_MONEY_H
