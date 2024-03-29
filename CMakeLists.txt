# ##########################################
# Check for a valid version of CMake

cmake_minimum_required( VERSION 3.0 FATAL_ERROR )

# ##########################################
# Start the project
project ( lightstone-work )

# enable the C++ 17 std libraries
set (CMAKE_CXX_FLAGS "-std=c++1z")

# enable the C++ 17 std libraries
set (CMAKE_CXX_FLAGS "-std=c++1z")

# ###############################################
# Find the threading package for this machine.
# Needed by gtest
find_package( Threads )

include ( external/CMakeLists.txt )

# ##################
# By setting CMAKE_MODULE_PATH cmake will find FindLibUSB in
# this project's support folder.
# The target_link_libraries configuration is where
# ${LibUSB_LIBRARIES} is used.

set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/support)

find_package ( LibUSB )
if ( LibUSB_FOUND )
  include_directories( ${LibUSB_INCLUDE_DIRS} )
endif ( LibUSB_FOUND )

add_subdirectory( library )
#add_subdirectory( application )

enable_testing()

add_subdirectory( test )
