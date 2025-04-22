set(LEETCODE_TESTS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LEETCODE_TESTS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${LEETCODE_TESTS_SRC_DIR}/*.cpp)

add_executable(fibonacci_numbers_tests
  ${SOURCES}
)

target_include_directories(fibonacci_numbers_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/projects/leetcode/include
)

target_link_libraries(fibonacci_numbers_tests
    gtest
    gtest_main
    gmock
    gmock_main
    leetcode
    pthread
)

add_test(NAME FibonacciNumbersTests COMMAND fibonacci_numbers_tests)
