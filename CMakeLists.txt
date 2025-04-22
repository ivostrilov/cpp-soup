cmake_minimum_required(VERSION 3.26)
project(MyProject VERSION 0.1.0 LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build tests" OFF)

# Enable warnings (GCC/Clang only — can extend for MSVC)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Set output directories (optional but good for structure)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(projects/hello_world)
add_subdirectory(projects/leetcode)
add_subdirectory(projects/lock_free)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(thirdparty/googletest)
  add_subdirectory(tests/leetcode)
  add_subdirectory(tests/lock_free)
endif()
