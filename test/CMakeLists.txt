add_executable( libraryTests "" )

target_sources(
    libraryTests
    PRIVATE
        LightstoneDriverTest.cpp
        RawCaptureTest.cpp
        LightstonePairTest.cpp
        main.cpp
    )

target_link_libraries(
    libraryTests
    PRIVATE
        lightstone
        gmock
        ${LibUSB_LIBRARIES}
    )

add_test( libraryTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libraryTests)
