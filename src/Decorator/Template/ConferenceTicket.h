#ifndef SRC_DECORATOR_TEMPLATE_CONFERENCETICKET_H
#define SRC_DECORATOR_TEMPLATE_CONFERENCETICKET_H

#include <string>
#include <utility>

#include "Money.h"

namespace decorator {
class ConferenceTicket {
 public:
  ConferenceTicket(std::string name, Money price)
      : name_{std::move(name)}, price_{price} {}

  std::string const& name() const { return name_; }
  Money price() const { return price_; }

 private:
  std::string name_;
  Money price_;
};

}  // namespace decorator

#endif  // SRC_DECORATOR_TEMPLATE_CONFERENCETICKET_H
