add_library(lightstone SHARED "")

target_sources(
  lightstone
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/Lightstone.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/LightstonePair.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/RawCapture.cpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Lightstone.h
    ${CMAKE_CURRENT_LIST_DIR}/include/LightstonePair.h
    ${CMAKE_CURRENT_LIST_DIR}/include/RawCapture.h
  )

target_include_directories(
  lightstone
  PUBLIC
    include
  )

target_link_libraries(
    lightstone
    PRIVATE
        ${LibUSB_LIBRARIES}
    )
