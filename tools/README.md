# tools

## USB calls
The liblightstone gives some good starting information on how to read data
from the Lightstone device. It does not use any USB control calls. I was curious
what the game `Journey to the Wild Divine` was doing when I was in a part of the
game that actively involved the Lightstone.

Since I am running Windows 7 with VMWare Fusion on my Mac Book Pro, I wondered
if there was a way to capture the USB calls from Windows into the Mac. I came
across the following:

- [VUSB Analyzer](http://vusb-analyzer.sourceforge.net)
  The tutorial page gave instructions on how to configure VMWare to be in debug
  mode and how to make sure that the USB calls were saved to the log file.


## Setup VUSB-analyzer on Ubuntu 18.04

The analyzer is written in Python 2.7 and a number of packages needed to be
installed to get the code to work. I had to make a change to the source code,
which is why I have placed it in this repository.

**TO BE ADDED LATER**
List of packages to be added to Ubuntu 18.04.
