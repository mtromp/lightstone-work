# Support files

These are files that I needed to make the build easier.

## FindLibUSB.cmake

This is located in `/usr/share/cmake-3.10/Modules` and was found on line here:
[codeaurora.org](https://source.codeaurora.org/external/thundersoft/qrd7225-ds-froyo/plain/external/thunderst/openobex/CMakeModules/FindLibUSB.cmake?id=cf2880e06f7f20cb3f10f8ee386924e4d0fe6fc9)

I made one modification so that it would find libusb-1.0, not simple libusb.
