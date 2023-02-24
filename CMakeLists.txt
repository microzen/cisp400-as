cmake_minimum_required(VERSION 3.24)
project(CISP400)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_BUILD_TYPE Debug)

# ---------------------
# Google Test
# ---------------------
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

set(TEST_FILES
        tst/matrices_test.cpp
        Matrices/Matrices.cpp
        )

add_executable(tst ${TEST_FILES})

target_link_libraries(tst gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tst)

#----------------------
# My Project
# ---------------------

include_directories(Matrices/)
#
set(MA_SOURCE_FILES Matrices/main.cpp Matrices/Matrices.cpp)
##add_library(Matrices/main.cpp Matrices/Matrices.h)
add_executable(matrices ${MA_SOURCE_FILES})

