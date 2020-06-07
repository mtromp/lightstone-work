#include "Lightstone.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class LightstoneTest : public Test
{
protected:
  Lightstone testLightstone;
};

TEST(LightstoneDriver, InstantiatingLightstoneReturnsObject)
{
  Lightstone* lightstone = new Lightstone();

  ASSERT_NE(lightstone, nullptr);
}

TEST_F(LightstoneTest, CreatingLightstoneSucceeds)
{
  int status = testLightstone.create();

  ASSERT_EQ(status, 0);
}

TEST_F(LightstoneTest, OpenLightstoneSucceeds)
{
  testLightstone.create();
  int status = testLightstone.open();

  EXPECT_EQ(status, 0);
}

TEST_F(LightstoneTest, OpenedLightstoneReturnsTrueFromisOpen)
{
  testLightstone.create();
  testLightstone.open();

  EXPECT_TRUE(testLightstone.isOpen());
}

TEST_F(LightstoneTest, ClosingAnOpenedLightstoneReturnsFalseFromisOpen)
{
  testLightstone.create();
  testLightstone.open();
  testLightstone.close();

  EXPECT_FALSE(testLightstone.isOpen());
}
