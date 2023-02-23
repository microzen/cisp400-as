# Google Test in CMake from GitHub (Source Files)

```cmake
# Build the GTest library

set(GTEST_SOURCE_DIR gtest_source_path)
set(GTEST_EXECUTE_FILE your_test.cpp)

add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/gtest)
include_directories(${GTEST_SOURCE_DIR}/include)


# Add your source files and test files here
add_executable(tst ${GTEST_EXECUTE_FILE})

# Link your test executable with the GTest library
target_link_libraries(tst gtest)
```