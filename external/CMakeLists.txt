# ###################################
# This file is included so that variables
# will be available throughout the project
#

# specify the external tools that are needed to be built
ADD_SUBDIRECTORY( external/googletest )

# ##################################
# set some things to make it easy to use gtest and gmock
SET ( GMOCK_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googlemock/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googletest/include
    )

# Add the gmock include directories. This will all the
# include directive to be <gmock/gmock.h> or <gtest/gtest.h>
INCLUDE_DIRECTORIES( ${GMOCK_INCLUDE_DIRS} )

# #############################
