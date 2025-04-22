set(LOCK_FREE_TESTS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LOCK_FREE_TESTS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${LOCK_FREE_TESTS_SRC_DIR}/*.cpp)

add_executable(lock_free_tests
  ${SOURCES}
)

target_include_directories(lock_free_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/projects/lock_free/include
)

target_link_libraries(lock_free_tests
    gtest
    gtest_main
    gmock
    gmock_main
    pthread
)

add_test(NAME LockFreeTests COMMAND lock_free_tests)
