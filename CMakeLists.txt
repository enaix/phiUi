cmake_minimum_required (VERSION 3.7)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 23)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

project(phi_desktop)

file(GLOB_RECURSE PHI_FILES include/*.h include/*.cpp)

add_executable(phi_desktop src/desktop_test.cpp ${PHI_FILES})

message("${PHI_FILES}")

include_directories(include)

# Configuring Phi
# ===============

# We are enabling monochrome desktop renderer
add_definitions(-DDESKTOP -DMONOCHROME)

# We set resolution to 128x64
add_definitions(-DDISPLAY_WIDTH=128 -DDISPLAY_HEIGHT=64)

# ===============

# Setting up SDL2
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

if(TARGET SDL2::SDL2main)
    target_link_libraries(phi_desktop PRIVATE SDL2::SDL2main)
endif()

#include_directories(phi_desktop ${SDL2_INCLUDE_DIRS})
target_link_libraries(phi_desktop PRIVATE SDL2::SDL2)