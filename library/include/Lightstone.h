#ifndef LIGHTSTONE_H
#define LIGHTSTONE_H

#include <libusb.h>

class Lightstone
{
public:
  Lightstone();
  ~Lightstone();

  //connect to the libusb and setup the data structures
  int create();
  int open();
  int close();
  bool isOpen();

private:
  libusb_context* context;
  bool opened = false;
};

#endif // LIGHTSTONE_H
