cmake_minimum_required(VERSION 3.24)
project(CISP400)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# ---------------------
# Google Test
# ---------------------
set(GTEST_SOURCE_DIR ./lib/googletest)
set(GTEST_EXECUTE_FILE ./tst/test.cpp)

# Build the GTest library
add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/gtest)
include_directories(${GTEST_SOURCE_DIR}/include)

# Add your source files and test files here
add_executable(tst ${GTEST_EXECUTE_FILE})

# Link your test executable with the GTest library
target_link_libraries(tst gtest)

