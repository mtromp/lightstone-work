#include "Lightstone.h"
#include "RawCapture.h"

#include <cstddef>

Lightstone::Lightstone()
{

}

Lightstone::~Lightstone()
{
  if (this->isOpen())
  {
    this->close();
  }
  libusb_free_device_list(this->devices, 1);
}

int Lightstone::create()
{
  int retStatus = libusb_init(&this->context);
  if (retStatus == 0 )
  {
    this->initialized = true;
  }
  return retStatus;
}

int Lightstone::open()
{
  int retStatus = this->ERROR_INIT;
  if (this->initialized)
  {
    int numDevices = getDeviceList();
    if (numDevices > 0)
    {
      if (findAndExtractLightstone())
      {
        this->opened = true;
        if(libusb_kernel_driver_active(this->lightstoneDeviceHandle, 0))
          {
            libusb_detach_kernel_driver(this->lightstoneDeviceHandle, 0);
          }
          retStatus = libusb_claim_interface(this->lightstoneDeviceHandle, 0);
      }
    }

  }
  return retStatus;
}

int Lightstone::close()
{
  libusb_release_interface(this->lightstoneDeviceHandle, 0);
  libusb_close(this->lightstoneDeviceHandle);
  this->opened = false;
  return 0;
}

bool Lightstone::isOpen()
{
  return this->opened;
}

LightstonePair Lightstone::readOnePair()
{
  LightstonePair thePair;
  int transferCount;
  unsigned char theBlock[BLOCK_SIZE+1];
  theBlock[BLOCK_SIZE] = 0; //terminate the block.
  RawCapture localRawCapture;
  bool rawCaptureComplete;
  if (this->isOpen())
  {
    while(1)
    {
      transferCount = this->readBlock(theBlock);
      if (transferCount > 0)
      {
        rawCaptureComplete = localRawCapture.extractText(theBlock);
        if (rawCaptureComplete)
        {
          thePair.parseString(localRawCapture.returnTextAsString());
          break;
        }
      }
    }
  }
  return thePair;
}

int Lightstone::getDeviceList()
{
  int errorCode = libusb_get_device_list(context, &devices);
  return errorCode;
}

bool Lightstone::findAndExtractLightstone()
{
  bool foundDevice=false;

  libusb_device* device;
  size_t deviceIndex = 0;
  int errorCode;

  while ((device = this->devices[deviceIndex++]) != NULL)
  {
    struct libusb_device_descriptor descriptor;
    errorCode = libusb_get_device_descriptor(device, &descriptor);
    if (errorCode < 0)
    {
      return foundDevice;
    }
    if (descriptor.idVendor == 0x0483 && descriptor.idProduct == 0x0035)
    {
      if((errorCode = libusb_open(device, &this->lightstoneDeviceHandle)) >= 0)
      {
        foundDevice = true;
        break;
      }
    }
  }
  return foundDevice;
}

int Lightstone::readBlock(unsigned char* block)
{
  int transferCount = 0;
  int retCode = libusb_bulk_transfer(
        this->lightstoneDeviceHandle, //Device Handle
        this->END_POINT,  //Device Endpoint address (0x81 who discovered that?)
        block,            // buffer where the data goes
        this->BLOCK_SIZE, // length of data buffer
        &transferCount,   // Actual length transferred
        this->TIMEOUT);  // timeout for transfer in milliseconds
  return transferCount;
}
