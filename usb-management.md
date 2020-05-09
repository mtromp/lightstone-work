# USB Management

I want to have the lightstone be connected to USB and not have the standard
usb driver talking to it, so that the liblightstone driver can connect and
capture data from it.

## Useful commands

```
lsusb  ## list usb devices

## the following presents information from the /sys/bus/usb/devices directory
for device in $(ls /sys/bus/usb/devices/*/product); do echo $device;cat $device;done

## The following code snippet homes in on the information just for this device
export idVendor="0483"
export idProduct="0035"
find -L /sys/bus/usb/devices/ -maxdepth 2 -name idVendor -exec grep -l $idVendor {} \; | \
  while read line; do \
    location=$(dirname $line); \
    grep -q $idProduct $location/idProduct;
    if [ "$?" -eq "0" ]; then \
      echo $location;
    fi
  done

###
udevadm info -a -p /sys/bus/usb/devices/1-3

```

## udev rule
I created `81-lightstone.rules` in `/etc/udev/rules.d/` that contains the following 2 lines:

```
# STMicroelectronics Lightstone should be disabled and should be available to mtromp/mtromp (user group).
SUBSYSTEM=="usb", ACTION=="add" ATTR{removable}=="removable" ATTR{idVendor}=="0483", ATTR{idProduct}=="0035", ATTR{authorized}="0" OWNER="mtromp" GROUP="mtromp"

## test the rule with
udevadm test --action="add" /devices/pci0000:00/0000:00:14.0/usb1/1-4  # /devices from the for device in

## To reload the udev information:
sudo udevadm control --reload
```

I verified that "authorized" is set to zero. I wonder if I need to set the
drivers to empty. This did not appear to work.

Sequence that helps identify the testing
```
for device in $(ls /sys/bus/usb/devices/*/product); do echo $device;cat $device;done
## look for ST7 RS232 USB BIOFBK and copy the line above it
## place that line at the end of the following:
udevadm info -ap <HERE'S WHERE TO PLACE THE PATH /sys/bus/usb.....>
## The output starts with looking at device '/devices/........'
## copy the information within the single-quotes, and paste it in the following command:
sudo udevadm test --action="add" <PASTE INFO HERE>
## Look in the output for our rule and make sure there are no errors.

``


## Resources

- https://wiki.gentoo.org/wiki/Allow_only_known_usb_devices
- https://blog.sleeplessbeastie.eu/2018/06/25/how-to-disable-usb-device/
- https://www.kernel.org/doc/html/latest/driver-api/usb/hotplug.html ## obsolete
- https://www.tecmint.com/udev-for-device-detection-management-in-linux/
- https://linuxconfig.org/tutorial-on-how-to-write-basic-udev-rules-in-linux
- http://www.reactivated.net/writing_udev_rules.html
