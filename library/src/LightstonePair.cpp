#include "LightstonePair.h"

LightstonePair::LightstonePair() : sclFloat(0.0), hrvFloat(0.0)
{

}

bool LightstonePair::parseString(std::string theRawString)
{
  bool success = false;

  if (theRawString.find("<RAW>") != std::string::npos)
  {
    std::string sclString = theRawString.substr(5,4);
    std::string hrvString = theRawString.substr(10,4);
    unsigned int sclMSB = this->hex2dec(sclString.substr(0,2));
    unsigned int sclLSB = this->hex2dec(sclString.substr(2,2));
    this->sclFloat = (float)(((sclMSB) << 8) | (sclLSB)) * 0.01;

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

float LightstonePair::getSCL()
{
  return this->sclFloat;
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
