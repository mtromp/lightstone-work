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
  const int ERROR_INIT = -1;

private:
  int getDeviceList();
  bool findAndExtractLightstone();
  libusb_context* context = nullptr;
  bool opened = false;
  bool initialized = false;

  libusb_device** devices = nullptr;
  libusb_device_handle* lightstoneDeviceHandle = nullptr;
};

#endif // LIGHTSTONE_H
