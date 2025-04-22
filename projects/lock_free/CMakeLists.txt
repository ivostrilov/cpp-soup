project(lock_free LANGUAGES CXX)

# Установка путей
set(LOCK_FREE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LOCK_FREE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${LOCK_FREE_SRC_DIR}/*.cpp)

# Библиотека
add_library(lock_free STATIC)

target_sources(lock_free PRIVATE
  ${SOURCES}
)

target_include_directories(lock_free PUBLIC ${LOCK_FREE_INCLUDE_DIR})
