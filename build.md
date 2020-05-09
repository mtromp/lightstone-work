# Building lightstone-work

I am building an application for the lightstone which will
need a library to talk to the usb lightstone. I am basing
my code on the excellent work that Kyle Machulis did with
[liblightstone](https://github.com/mtromp/liblightstone), which I forked.

## Prerequisites:

- Ubuntu 18.04
- cmake `sudo apt install cmake`
- gmock `sudo apt install google-mock`
- FindGMock.cmake from https://gitlab.enseeiht.fr/abcd/abcd/tree/mumps_scaling/cmake/Modules
  - place in `/usr/share/cmake-3.10/Modules`

## Setup directory structure

- lightstone-work
  - test
  - library
  - application

## Created top CMakeLists.txt

Could not find GTest/GMock 
