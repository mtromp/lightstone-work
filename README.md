# lightstone-work
Create a liblightstone that builds on ubuntu18.04, and add other capabilities.

## Other useful documents in this repository

- [How to Build](build.md)
- [FindLibUSB.cmake](support/README.md)
- [Detective Work](tools/README.md)

## Steps to successfully build liblightstone

- Fork qdot/liblightstone into [my github space](https://github.com/mtromp/liblightstone).
- Clone my copy into `~/workspace/lightstonework/`
- Make sure `libusb` is installed: `sudo apt install libusb-dev`
- In bash do the following:
```bash
cd ~/workspace/lightstonework/liblightstone
mkdir build
cd build
cmake ..
make
```

## udev rule needed to run lightstone_test

A udev rule needed to be installed to allow access to the
device interface. The rule does the following:

- Identifies the usb device by vendor and product number
- Provides access to the group: users
- Sets read/write access to all: owner/group/world

```bash
cd /etc/udev/rules.d/
sudo vi 81-lightstone.rules
## SUBSYSTEM=="usb", \
## ATTR{removable}=="removable", \
## ATTR{idVendor}=="0483", \
## ATTR{idProduct}=="0035", \
## MODE:="666", \
## GROUP="users"
```

The information in the code block with `##` are on a single
line (the backslashes are meant to indicate that) and are
the contents of the file, which I named `81-lightstone.rules`.

`SUBSYSTEM=="usb", ATTR{removable}=="removable", ATTR{idVendor}=="0483", ATTR{idProduct}=="0035", MODE:="666", GROUP="users"`

### Questions about the udev rule.
I would still like to experiment to see which parts are
essential and which I just put in because of the example
that I was copying. My questions are:
- Is the removable attribute needed?
- Is the mode sufficient, and group is extraneous?
- Is it necessary to have mode be set with `:=` or will `=` work?

## Next Steps

I will create my own version of liblightstone just for
Ubuntu 18.04 at this time, with the following goals:
- Use Test Driven Development so that I have a set of automated tests.
- Set up CMAKE to allow out-of-source-tree builds.
  - This means that the build directory would not be
    below the git directory.
  - This allows using grep within the source tree without having to specify ignoring directories.
  - This avoid needing entries in the .gitignore file.
- Use QTCreator for the IDE
  - QTCreator, by default does out-of-source builds with different directories for debug and non-debug builds.


## Other things

I will start to create github issues to identify my intended work. I will make this repository public so that others have visibility into what I am doing.

The spike branch contains some helpful information for viewing and controlling udev. Bring that markdown file, with improvements into master.
