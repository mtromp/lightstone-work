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
