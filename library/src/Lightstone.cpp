#include "Lightstone.h"

Lightstone::Lightstone()
{

}

Lightstone::~Lightstone()
{
  if (this->isOpen())
  {
    this->close();
  }
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
    this->opened = true;
    retStatus = 0;
  }
  return retStatus;
}

int Lightstone::close()
{
  this->opened = false;
  return 0;
}

bool Lightstone::isOpen()
{
  return this->opened;
}
