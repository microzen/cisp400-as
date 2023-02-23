# Use CMake in The Project

Use `cmake_minimum_required(VERSION 3.24)` to limit the version.

```cmake
cmake_minimum_required(VERSION 3.24)

project(YOUR PROJECT)

set(CMAKE_CXX_STANDARD 17)

add_executable(target_name main.cpp)
```