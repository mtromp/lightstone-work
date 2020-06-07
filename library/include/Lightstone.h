#ifndef LIGHTSTONE_H
#define LIGHTSTONE_H

#include <libusb.h>

class Lightstone
{
public:
  Lightstone();
  //connect to the libusb and setup the data structures
  int create();
  int open();

private:
  libusb_context* context;


};

#endif // LIGHTSTONE_H
