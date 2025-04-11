cmake_minimum_required(VERSION 3.14)
project(CalculatorTDD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

add_executable(test_calculator
    calculator.cpp
    test_calculator.cpp
)

target_link_libraries(test_calculator gtest_main)

include(GoogleTest)
gtest_discover_tests(test_calculator)
