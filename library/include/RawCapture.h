#ifndef RAWCAPTURE_H
#define RAWCAPTURE_H

#include <libusb.h>

class RawCapture
{
public:
  RawCapture();

  bool extractText(unsigned char* block);
  void returnText(unsigned char block[20]);

private:
  void moveText(unsigned char* text, int start, int count);

  unsigned char readyBlock[20];
  int readyPointer;

  bool foundInitialRaw;
  bool foundFinalRaw;
};

#endif // RAWCAPTURE_H
