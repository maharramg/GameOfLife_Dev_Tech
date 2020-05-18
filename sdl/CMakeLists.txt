cmake_minimum_required(VERSION 3.0)

project(sdl LANGUAGES C)

set(SOURCES sdl.c)
set(HEADERS sdl.h)

set(CMAKE_BUILD_TYPE Release)

list(APPEND CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/cmake/SDL2)
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_library(sdl)

target_sources(sdl PRIVATE ${SOURCES} ${HEADERS})
target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sdl PUBLIC ${SDL2_LIBRARIES} game)