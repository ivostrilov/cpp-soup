project(leetcode LANGUAGES CXX)

# Установка путей
set(LEETCODE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LEETCODE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${LEETCODE_SRC_DIR}/*.cpp)

# Библиотека
add_library(leetcode STATIC ${SOURCES})

target_sources(leetcode PRIVATE
  ${SOURCES}
)

target_include_directories(leetcode PUBLIC ${LEETCODE_INCLUDE_DIR})
