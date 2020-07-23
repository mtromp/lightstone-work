#ifndef RAWCAPTURE_H
#define RAWCAPTURE_H

#include <string>
#include <libusb.h>

class RawCapture
{
public:
  RawCapture();
  static const int CAPTURE_SIZE=21; // 20 plus terminator

  bool extractText(unsigned char* block);
  void returnText(unsigned char block[CAPTURE_SIZE]);
  std::string returnTextAsString();

private:
  void moveText(unsigned char* text, int start, int count);

  unsigned char readyBlock[CAPTURE_SIZE];
  int readyPointer;

  bool foundInitialRaw;
  bool foundFinalRaw;
};

#endif // RAWCAPTURE_H
