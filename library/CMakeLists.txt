add_library(lightstone SHARED "")

target_sources(
  lightstone
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/Lightstone.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/Lightstone.h
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
