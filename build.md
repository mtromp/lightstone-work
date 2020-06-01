# Building lightstone-work

I am building an application for the lightstone which will
need a library to talk to the usb lightstone. I am basing
my code on the excellent work that Kyle Machulis did with
[liblightstone](https://github.com/mtromp/liblightstone), which I forked.

## Prerequisites:

- Ubuntu 18.04
- cmake `sudo apt install cmake`
- gmock `sudo apt install google-mock`
- create a symlink to googletest so that the gmock/gtest libraries are built
  during the application build. This ensures the same compiler flags are used
  for the application/library/test and for gtest/gmock.

## Setup directory structure

- lightstone-work
  - test
  - library
  - external
  - application

```
cd ~/workspace/lightstone-work/external
ln -s /usr/src/googletest googletest
```

## Created CMakeLists.txt

Create enough of the CMaklists.txt structure and a main.cpp for tests to
verify that CMake is happy and it is possible to build.


