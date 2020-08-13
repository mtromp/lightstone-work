#include "LightstonePair.h"

LightstonePair::LightstonePair()
{

}

bool LightstonePair::parseString(std::string theRawString)
{
  bool success = false;

  if (theRawString.find("<RAW>") != std::string::npos)
  {
    std::string hrvString = theRawString.substr(10,4);
    std::string scrString = theRawString.substr(5,4);

    unsigned int hrvMSB = this->hex2dec(hrvString.substr(0,2));
    unsigned int hrvLSB = this->hex2dec(hrvString.substr(2,2));
    this->hrvFloat = (float)(((hrvMSB) << 8) | (hrvLSB)) * 0.001;
    success = true;

  }
  return success;
}

float LightstonePair::getHRV()
{
  return this->hrvFloat;
}

unsigned int LightstonePair::hex2dec(std::string charPair)
{
  unsigned int i;
  unsigned int value = 0;

  for (i = 0; i < 2; i++)
  {
    value = value * 0x10;
    if (charPair[i] >= '0' && charPair[i] <= '9')
    {
      value += charPair[i]-'0';
    }
    else if (charPair[i] >= 'A' && charPair[i] <= 'F')
    {
      value += charPair[i]-'A' + 10;
    }
  }
  return value;
}
