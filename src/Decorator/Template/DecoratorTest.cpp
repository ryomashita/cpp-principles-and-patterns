#include <gtest/gtest.h>

#include "ConferenceTicket.h"
#include "Money.h"
#include "PricedItems.h"  // IWYU pragma: keep

using namespace decorator;

TEST(DecoratorTemplateTest, Money) {
  Money money{100};
  Money money2{100};
  EXPECT_EQ(money, money2);
  money = money * 2;
  EXPECT_EQ(money, Money{200});
  money = money + Money{50};
  EXPECT_EQ(money, Money{250});
};

TEST(DecoratorTemplateTest, PricedItem) {
  ConferenceTicket ticket{"item", Money{500}};

  Taxed<0.08, Discounted<0.2, ConferenceTicket>> item{"item", Money{500}};

  EXPECT_EQ(item.price(), Money{500 * 0.8 * 1.08});
}
