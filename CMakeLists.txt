cmake_minimum_required(VERSION 3.14)
project(cleancode)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the main executable target
add_executable(cleancode
    main.c
    soundex.c
)

# Add the test executable target
add_executable(SoundexTests
    Soundex.Tests.cpp
)

# Link GoogleTest to the test executable
target_link_libraries(SoundexTests
    GTest::gtest_main
)

# Include directories for your source files and headers
include_directories(${CMAKE_SOURCE_DIR})

# Compile options for coverage if needed
add_compile_options(--coverage)

# Discover and add GoogleTest tests
include(GoogleTest)
gtest_discover_tests(SoundexTests)
