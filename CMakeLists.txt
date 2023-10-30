cmake_minimum_required(VERSION 3.22)

project(UnityCUnitTests
  VERSION 1.0
  LANGUAGES C)

# Global definitions
include_directories(include)
add_compile_options(-W -Wall -Wextra -pedantic -std=c17)

# Main executable, release
add_executable(main
  src/main.c
  src/string_to_float.c
)

target_link_libraries(main m)

target_compile_options(main PRIVATE -O3)
target_link_options(main PRIVATE -s)

# Unit test executable
add_executable(run_unit_tests
  src/unity.c
  src/string_to_float.c
  test/test_string_to_float.c
)
target_link_libraries(run_unit_tests m)

target_compile_options(run_unit_tests PRIVATE -O0 -ggdb3 )
target_link_options(run_unit_tests BEFORE PRIVATE -lasan )

