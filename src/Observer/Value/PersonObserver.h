#ifndef SRC_OBSERVER_VALUE_PERSONOBSERVER_H
#define SRC_OBSERVER_VALUE_PERSONOBSERVER_H

#include <string>

#include "Observer.h"
#include "Person.h"

namespace observer {
std::string propertyChanged(Person const& person,
                            Person::StateChange property) {
  switch (property) {
    case Person::StateChange::forenameChanged:
      return person.forename() + " " + person.surname();
    case Person::StateChange::surnameChanged:
      return person.forename() + " " + person.surname();
    case Person::StateChange::addressChanged:
      return std::string{};
    default:
      return std::string{};
  }
}

using PersonObserver = Observer<Person, Person::StateChange>;

auto addressChanged = [](Person const& person, Person::StateChange property) {
  if (property == Person::StateChange::addressChanged)
    return person.address();
  else
    return std::string{};
};
}  // namespace observer

#endif  // SRC_OBSERVER_VALUE_PERSONOBSERVER_H
