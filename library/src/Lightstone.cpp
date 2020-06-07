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
  return 0;
}

int Lightstone::open()
{
  this->opened = true;
  return 0;
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
