#include "Lightstone.h"
#include <stdio.h>

int main(int /*argc*/, char** /*argv*/)
{
  Lightstone myLightstone;
  int status;
  status = myLightstone.create();
  printf("Created a lightstone\n");
  status = myLightstone.open();
  printf("Opened lightstone with status: %d\n", status);

  LightstonePair thePair = myLightstone.readOnePair();

  printf("Pair read: %f %f\n", thePair.heartRateVariability, thePair.skinConductance);

  myLightstone.close();
  return 0;
}
