#ifndef LIGHTSTONEPAIR_H
#define LIGHTSTONEPAIR_H

#include <string>

class LightstonePair
{
public:
  LightstonePair();
  bool parseString(std::string theRawString);
  float getHRV();
  float getSCL();

private:
  unsigned int hex2dec(std::string charPair);

  float sclFloat;
  float hrvFloat;
};

#endif // LIGHTSTONEPAIR_H
