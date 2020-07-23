#include "RawCapture.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(RawCapture, ProvidesATextStringWithData)
{
    bool returnedValue;
  //05 3c 52 41 57 3e 3e 0a                         <RAW>
  //07 30 32 31 41 20 30 37                         021A 07
  //07 45 45 3c 5c 52 41 57                         EE<\RAW
  //03 3e 0a 0d 5c 52 41 57                         >..

  unsigned char rawData1[8] =
     {0x05, 0x3c, 0x52, 0x41, 0x57, 0x3e, 0x3e, 0x0a};
  unsigned char rawData2[8] =
     {0x07, 0x30, 0x32, 0x31, 0x41, 0x20, 0x30, 0x37};
  unsigned char rawData3[8] =
     {0x07, 0x45, 0x45, 0x3c, 0x5c, 0x52, 0x41, 0x57};
  unsigned char rawData4[8] =
     {0x03, 0x3e, 0x0a, 0x0d, 0x5c, 0x52, 0x41, 0x57};

  RawCapture localRawCapture;
  returnedValue = localRawCapture.extractText(rawData1);
  EXPECT_FALSE(returnedValue);
  returnedValue = localRawCapture.extractText(rawData2);
  EXPECT_FALSE(returnedValue);
  returnedValue = localRawCapture.extractText(rawData3);
  EXPECT_FALSE(returnedValue);
  returnedValue = localRawCapture.extractText(rawData4);
  EXPECT_TRUE(returnedValue);

  std::string myString = localRawCapture.returnTextAsString();

  EXPECT_EQ(myString[5], '0');
}

TEST(RawCapture, DataStartingInMiddleOfBlockStillWorks)
{
  bool returnedValue;

  //  07 0d 3c 52 41 57 3e 30                         .<RAW>0
  //  07 32 31 43 20 30 38 35                         21C 085
  //  07 37 3c 5c 52 41 57 3e                         7<\RAW>
  unsigned char rawData1[8] =
     {0x07, 0x0d, 0x3c, 0x52, 0x41, 0x57, 0x3e, 0x30};
  unsigned char rawData2[8] =
     {0x07, 0x32, 0x31, 0x43, 0x20, 0x30, 0x38, 0x35};
  unsigned char rawData3[8] =
     {0x07, 0x37, 0x3c, 0x5c, 0x52, 0x41, 0x57, 0x3e};
  RawCapture localRawCapture;
  returnedValue = localRawCapture.extractText(rawData1);
  returnedValue = localRawCapture.extractText(rawData2);
  returnedValue = localRawCapture.extractText(rawData3);

  unsigned char theText[RawCapture::CAPTURE_SIZE];
  localRawCapture.returnText(theText);

  EXPECT_EQ(theText[5], '0');

}

TEST(RawCapture, TagsSplitAcrossBlocksStillWorks)
{
  bool returnedValue;

  //02 3c 52 0a 0d 5c 52 41                         <R
  //07 41 57 3e 30 32 31 45                         AW>021E
  //07 20 30 37 46 44 3c 5c                          07FD<\
  //06 52 41 57 3e 0a 0d 5c                         RAW>..

  unsigned char rawData1[8] =
     {0x02, 0x3c, 0x52, 0x0a, 0x0d, 0x5c, 0x52, 0x41};
  unsigned char rawData2[8] =
     {0x07, 0x41, 0x57, 0x3e, 0x30, 0x32, 0x31, 0x45};
  unsigned char rawData3[8] =
     {0x07, 0x20, 0x30, 0x37, 0x46, 0x44, 0x3c, 0x5c};
  unsigned char rawData4[8] =
     {0x06, 0x52, 0x41, 0x57, 0x3e, 0x0a, 0x0d, 0x5c};

  RawCapture localRawCapture;
  returnedValue = localRawCapture.extractText(rawData1);
  returnedValue = localRawCapture.extractText(rawData2);
  returnedValue = localRawCapture.extractText(rawData3);
  returnedValue = localRawCapture.extractText(rawData4);

  unsigned char theText[RawCapture::CAPTURE_SIZE];
  localRawCapture.returnText(theText);

  EXPECT_EQ(theText[5], '0');
}

TEST(RawCapture, SERtagWillAlsoBeReturned)
{
  bool returnedValue;

  //  07 57 3e 0a 0d 3c 53 45                         W>..<SE
  //  07 52 3e 30 30 30 30 3c                         R>0000<
  //  07 5c 53 45 52 3e 0a 0d                         \SER>..
  unsigned char rawData1[8] =
     {0x07, 0x57, 0x3e, 0x0a, 0x0d, 0x3c, 0x53, 0x45};
  unsigned char rawData2[8] =
     {0x07, 0x52, 0x3e, 0x30, 0x30, 0x30, 0x30, 0x3c};
  unsigned char rawData3[8] =
     {0x07, 0x5c, 0x53, 0x45, 0x52, 0x3e, 0x0a, 0x0d};

  RawCapture localRawCapture;
  returnedValue = localRawCapture.extractText(rawData1);
  returnedValue = localRawCapture.extractText(rawData2);
  returnedValue = localRawCapture.extractText(rawData3);

  unsigned char theText[RawCapture::CAPTURE_SIZE];
  localRawCapture.returnText(theText);

  EXPECT_EQ(theText[2], 'E');
}

TEST(RawCapture, FirstBlockHasBackslashToBeIgnored)
{
  bool returnedValue;
  //06 3c 5c 52 41 57 3e 41                         <\RAW>
  //02 3c 52 0a 0d 5c 52 41                         <R
  //07 41 57 3e 30 32 31 45                         AW>021E
  //07 20 30 37 46 44 3c 5c                          07FD<\
  //06 52 41 57 3e 0a 0d 5c                         RAW>..
  unsigned char rawData0[8] =
     {0x06, 0x3c, 0x5c, 0x52, 0x41, 0x57, 0x3e, 0x0a};
  unsigned char rawData1[8] =
     {0x02, 0x3c, 0x52, 0x0a, 0x0d, 0x5c, 0x52, 0x41};
  unsigned char rawData2[8] =
     {0x07, 0x41, 0x57, 0x3e, 0x30, 0x32, 0x31, 0x45};
  unsigned char rawData3[8] =
     {0x07, 0x20, 0x30, 0x37, 0x46, 0x44, 0x3c, 0x5c};
  unsigned char rawData4[8] =
     {0x06, 0x52, 0x41, 0x57, 0x3e, 0x0a, 0x0d, 0x5c};

  RawCapture localRawCapture;
  returnedValue = localRawCapture.extractText(rawData0);
  returnedValue = localRawCapture.extractText(rawData1);
  returnedValue = localRawCapture.extractText(rawData2);
  returnedValue = localRawCapture.extractText(rawData3);
  returnedValue = localRawCapture.extractText(rawData4);

  unsigned char theText[RawCapture::CAPTURE_SIZE];
  localRawCapture.returnText(theText);

  EXPECT_EQ(theText[5], '0');

}
