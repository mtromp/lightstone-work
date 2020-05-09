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

find_package ( GTest REQUIRED )

add_subdirectory( library )
add_subdirectory( application )

enable_testing()

add_subdirectory( test )
