add_executable( libraryTests "" )

target_sources(
    libraryTests
    PRIVATE
        lightstoneDriverTest.cpp
        main.cpp
    )

target_link_libraries(
    libraryTests
    PRIVATE
        gmock
    )

add_test( libraryTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libraryTests)
