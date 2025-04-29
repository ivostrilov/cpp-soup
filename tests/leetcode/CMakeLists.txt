set(LEETCODE_TESTS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LEETCODE_TESTS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${LEETCODE_TESTS_SRC_DIR}/*.cpp)

add_executable(leetcode_tests
  ${SOURCES}
)

target_include_directories(leetcode_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/projects/leetcode/include
)

target_link_libraries(leetcode_tests
    gtest
    gtest_main
    gmock
    gmock_main
    leetcode
    pthread
)

add_test(NAME LeetcodeTests COMMAND leetcode_tests)
