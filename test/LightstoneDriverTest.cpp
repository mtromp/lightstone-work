#include "Lightstone.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(LightstoneDriver, CreatingLightstoneReturnsInitializedObject)
{
  Lightstone* lightstone = new Lightstone();

  EXPECT_NE(lightstone, nullptr);
}
