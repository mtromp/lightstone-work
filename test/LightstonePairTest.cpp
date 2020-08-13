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

TEST(LightstonePair, PopulatesSCFromString)
{
  std::string rawString("<RAW>021A 07EE<\\RAW>");
  LightstonePair localPair;
  bool success = localPair.parseString(rawString);

  EXPECT_TRUE(success);
  float sclData = localPair.getSCL();
  EXPECT_FLOAT_EQ(5.38, sclData);
}

TEST(LightstonePair, ReturnsErrorWhenPassedSERstring)
{
  std::string rawString("<SER>0000<\\SER>");
  LightstonePair localPair;

  bool success = localPair.parseString(rawString);

  EXPECT_FALSE(success);
}
