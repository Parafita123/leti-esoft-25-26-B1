cmake_minimum_required(VERSION 3.27)
project(CoreTests)

# Use FetchContent to download and build GoogleTest and GoogleMock if they are not provided
include(FetchContent)
include(CTest)
enable_testing()

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Define the test executable
add_executable(CoreTests
        domain/services/VaccinationProcessServiceTests.cpp
)

# Add include directories so that tests can find Core headers
target_include_directories(CoreTests PRIVATE
        ${CMAKE_SOURCE_DIR}/Core
)

# Link against the Core library and GoogleTest/GoogleMock targets
target_link_libraries(CoreTests
        PRIVATE
        Core
        GTest::gtest
        GTest::gmock
        GTest::gtest_main
)

# Register the test with CTest so that `ctest` will run it
add_test(NAME CoreTests COMMAND CoreTests)