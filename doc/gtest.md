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

GoogleTest Doc
```cmake
cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
```