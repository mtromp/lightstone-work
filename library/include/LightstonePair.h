#ifndef LIGHTSTONEPAIR_H
#define LIGHTSTONEPAIR_H

#include <string>

class LightstonePair
{
public:
  LightstonePair();
  bool parseString(std::string theRawString);
  float getHRV();

private:
  unsigned int hex2dec(std::string charPair);

  float hrvFloat;
  float scrFloat;
};

#endif // LIGHTSTONEPAIR_H
