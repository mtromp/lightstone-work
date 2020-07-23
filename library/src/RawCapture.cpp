#include "RawCapture.h"

RawCapture::RawCapture()
{
  this->readyPointer = -1;
  this->foundInitialRaw = false;
  this->foundFinalRaw = false;
}

// return true with we have a full <RAW>.....<\RAW> data string
bool RawCapture::extractText(unsigned char* block)
{
  bool retBool = false;
  int textCount = block[0];
  bool foundLessThan = false;
  int lessThanIndex = -1;
  bool foundGreaterThan = false;
  int greaterThanIndex = -1;
  bool foundBackslash = false;
  int backslashIndex = -1;

  unsigned char text[block[0]];
  for (int i = 0; i<textCount; i++)
  {
    text[i] = block[i+1];
    if (text[i] == 0x3c)
    {
      foundLessThan = true;
      lessThanIndex = i;
    }
    if (text[i] == 0x3e)
    {
      foundGreaterThan = true;
      greaterThanIndex = i;
    }
    if (text[i] == 0x5c)
    {
      foundBackslash = true;
      backslashIndex = i;
    }
  }
  // Are we looking for <?
  if (this->readyPointer == -1 && foundLessThan && !foundBackslash)
  {
    this->readyPointer = 0;
    moveText(text, lessThanIndex, textCount);
    if (foundGreaterThan && (lessThanIndex < greaterThanIndex))
    {
      this->foundInitialRaw = true;
    }
  } else if (this->readyPointer != -1) {
    int moveStart = 0;
    int moveCount = textCount;
    if (!this->foundInitialRaw && foundGreaterThan)
    {
      this->foundInitialRaw = true;
    } else {
      if (this->foundInitialRaw && foundGreaterThan)
      {
        this->foundFinalRaw = true;
        retBool = true;
        moveCount = greaterThanIndex+1;
      }
    }
    moveText(text, moveStart, moveCount);
  }
  return retBool;
}

void RawCapture::returnText(unsigned char block[20])
{
  for (int i = 0; i < this->readyPointer; i++)
  {
    block[i] = this->readyBlock[i];
    this->readyBlock[i] = 0;
  }
  this->readyPointer = -1;
  this->foundFinalRaw = false;
  this->foundInitialRaw = false;
}

void RawCapture::moveText(unsigned char* text, int start, int count)
{
  for (int i = start; i < count; i++)
  {
    this->readyBlock[this->readyPointer] = text[i];
    this->readyPointer++;
  }
}
