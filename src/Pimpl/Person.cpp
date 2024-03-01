#include "Person.h"

#include <memory>
#include <string>

namespace pimpl {

struct Person::Impl {
  std::string address;
  std::string city;
  std::string country;
  std::string zip;
  int year_of_birth;
};

Person::Person() : pimpl_(std::make_unique<Impl>()) {}
Person::~Person() = default;
Person::Person(Person const& other)
    : pimpl_(std::make_unique<Impl>(*other.pimpl_)) {}
Person& Person::operator=(Person const& other) {
  *pimpl_ = *other.pimpl_;
  return *this;
}

// noexcept が期待されるが、実際にはムーブする都合上例外を投げる可能性があるため
// noexcept を指定するのは避けるべき
Person::Person(Person&& other) noexcept
    : pimpl_{std::make_unique<Impl>(std::move(*other.pimpl_))} {}
Person& Person::operator=(Person&& other) noexcept {
  pimpl_ = std::move(other.pimpl_);
  return *this;
}

int Person::year_of_birth() const { return pimpl_->year_of_birth; }
void Person::set_year_of_birth(int year) { pimpl_->year_of_birth = year; }

}  // namespace pimpl