project(hello_world LANGUAGES CXX)

set(HELLO_WORLD_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HELLO_WORLD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${HELLO_WORLD_SRC_DIR}/*.cpp)

add_executable(
  hello_world 
  ${SOURCES}
)

target_link_libraries(hello_world PRIVATE
  lock_free
)
