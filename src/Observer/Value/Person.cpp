#include "Person.h"

namespace observer {
bool Person::attach(PersonObserver* observer) {
  auto [pos, success] = observers_.insert(observer);
  return success;
}

bool Person::detach(PersonObserver* observer) {
  return observers_.erase(observer) > 0;
}

void Person::notify(StateChange property) {
  // イテレーション中に detach
  // を呼び出せるように、範囲ループではなくイテレータを使う
  for (auto itr = begin(observers_); itr != end(observers_);) {
    auto const pos = itr++;
    (*pos)->update(*this, property);
  }
}

void Person::forename(std::string newForename) {
  forename_ = std::move(newForename);
  notify(StateChange::forenameChanged);
}

void Person::surname(std::string newSurname) {
  surname_ = std::move(newSurname);
  notify(StateChange::surnameChanged);
}

void Person::address(std::string newAddress) {
  address_ = std::move(newAddress);
  notify(StateChange::addressChanged);
}
}  // namespace observer
