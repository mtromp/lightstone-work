#ifndef LIGHTSTONE_H
#define LIGHTSTONE_H

#include <libusb.h>

class Lightstone
{
public:
  Lightstone();

private:
  libusb_context* context;


};

#endif // LIGHTSTONE_H
