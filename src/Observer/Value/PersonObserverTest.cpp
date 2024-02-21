#include <gtest/gtest.h>

#include "Observer.h"
#include "Person.h"
#include "PersonObserver.h"

using namespace observer;

TEST(ObserverValueTet, propertyChanged) {
  PersonObserver nameObserver(propertyChanged);
  Person homer("Homer", "Simpson");
  homer.attach(&nameObserver);
  homer.forename("Homer Jay");
  homer.surname("Simpson");
}

TEST(ObserverValueTet, addressChanged) {
  PersonObserver addressObserver(addressChanged);
  Person homer("Homer", "Simpson");
  homer.attach(&addressObserver);
  homer.address("742 Evergreen Terrace");
  homer.address("742 Evergreen Terrace");
  homer.detach(&addressObserver);
  homer.address("742 Evergreen Terrace");
}