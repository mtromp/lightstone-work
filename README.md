# lightstone-work
Create a liblightstone that builds on ubuntu18, and add other capabilities.

## 20200412 Notes
I obviously did not complete my notes last October. Will try to rebuild this
and make better notes.

```bash
cd ~/workspace/lightstonework/liblightstone/src/
mkdir build
cd build
cmake ..  # make with the CMakeFile in the src directory
## Did not work Erre about not having a minimum version of cmake specified
##    also, did not know what BUILDSYS_BUILD_LIB meant.
## No new files were written. All are dated Oct 19, 2019.

cd ~/workspace/lightstonework/liblightstone/src/
mkdir build2
cd build2
cmake ..
# this generated the same error.
# try to do this at the root level
cd ~/workspace/lightstonework/liblightstone/
mkdir build2 ## don't want to destroy the build directory that was create Oct 19, 2019
cd build2
cmake .. # successfully created a Makefile
make
cd bin
./lightstone_test ## found 1 lightstones but could not open it!

### SUCCESS #####
```
The README.asciidoc "The VID/PID pair of the lightstone will need to be blacklisted on
linux in order to use liblightstone there."
The blue lightstone has a VID/PID pair of **{0x0483, 0x0035}**
The white IOM device has a VID/PID pair of {0x14FA, 0x0001}

What this means is that we want to prevent the system USB driver from controlling
this device. It should be possible to identify which USB devices are found by the
OS.
```bash
lsusb  # this lists the usb deviced connected. The lightstone is there:
# Bus 001 Device 004: ID 0483:0035 STMicroelectronics

dmesg
# [    2.871784] usb 1-3: New USB device found, idVendor=0483, idProduct=0035, bcdDevice= 1.11
# [    2.871785] usb 1-3: New USB device strings: Mfr=3, Product=1, SerialNumber=0
# [    2.871786] usb 1-3: Product: ST7 RS232 USB BIOFBK
# [    2.871786] usb 1-3: Manufacturer: STMicroelectronics
# [    3.471036] hid-generic 0003:0483:0035.0004: hiddev2,hidraw3: USB HID v1.10 Device [STMicroelectronics ST7 RS232 USB BIOFBK] on usb-0000:00:14.0-3/input0

```
Created /etc/udev/rules.d/81-lightstone.rules with:
```
# STMicroelectronics Lightstone should be disabled
SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="0035", ATTR{authorized}="0"
```
Then ran the following command: `sudo udevadm control --reload`. Not sure if this works. Test still can't open the lightstone.
Device still shows up in `lsusb`. is SUBSYSTEM correct or does it need to have 1-3 in it?
`dmesg` shows `usb usb4` disconnecting a device, as well as `usb usb3` deregistering.

commented out the SUBSYSTEM line in 81-lightstone.rules and did a reload. No usb messages in the dmesg. Will Reenable that rule.

Unplug and replug in the Lightstone and the device is now Bus 001 Device 007 instead of Device 004

There were two crash notices. Will reboot.


## 20191019 Notes
The liblightstone that I cloned from https://github.com/openyou/liblightstone.git
built with the following steps:

```bash

```
