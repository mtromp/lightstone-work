add_executable( lightstone_test "" )

target_sources(
    lightstone_test
    PRIVATE
        lightstone_test.cpp
    )

target_link_libraries(
    lightstone_test
    PRIVATE
        lightstone
        ${LibUSB_LIBRARIES}
    )
