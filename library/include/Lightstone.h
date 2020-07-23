#ifndef LIGHTSTONE_H
#define LIGHTSTONE_H

#include <libusb.h>

typedef struct {
  float heartRateVariability;
  float skinConductance;
}LightstonePair;

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
  LightstonePair readOnePair();
  const int ERROR_INIT = -1;

private:
  int getDeviceList();
  bool findAndExtractLightstone();
  int readBlock(unsigned char* block);

  const int BLOCK_SIZE = 8;
  const unsigned char END_POINT = 0x81;
  const unsigned int TIMEOUT = 0x10;
  libusb_context* context = nullptr;
  bool opened = false;
  bool initialized = false;

  libusb_device** devices = nullptr;
  libusb_device_handle* lightstoneDeviceHandle = nullptr;
};

#endif // LIGHTSTONE_H
