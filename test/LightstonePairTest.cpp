#include "LightstonePair.h"

#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(LightstonePair, PopulatesHRVFromString)
{
  std::string rawString("<RAW>021A 07EE<\\RAW>");
  LightstonePair localPair;
  bool success = localPair.parseString(rawString);

  EXPECT_TRUE(success);
  float hrvData = localPair.getHRV();
  EXPECT_FLOAT_EQ(2.03, hrvData);

}
