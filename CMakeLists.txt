cmake_minimum_required (VERSION 3.7)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 23)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

project(phi_desktop)

file(GLOB_RECURSE PHI_FILES lib/*.h lib/*.cpp src/*.h)

message("${PHI_FILES}")

SET(libdir ${CMAKE_CURRENT_SOURCE_DIR}/lib)

FILE(GLOB children RELATIVE ${libdir} ${libdir}/*)
SET(PHI_INCL_DIRS "")
FOREACH(child ${children})
    IF(IS_DIRECTORY ${libdir}/${child})
        LIST(APPEND PHI_INCL_DIRS ${libdir}/${child})
    ENDIF()
ENDFOREACH()

message("${PHI_INCL_DIRS}")

include_directories(${PHI_INCL_DIRS} src)

add_executable(phi_desktop src/desktop_test.cpp ${PHI_FILES})

target_compile_options(phi_desktop PUBLIC -include custom_options.h)

# Configuring Phi
# ===============

# We are enabling monochrome desktop renderer
add_definitions(-DDESKTOP -DMONOCHROME)

# We set resolution to 128x64
#add_definitions(-DDISPLAY_WIDTH=128 -DDISPLAY_HEIGHT=64)

# ===============

# Setting up SDL2
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

if(TARGET SDL2::SDL2main)
    target_link_libraries(phi_desktop PRIVATE SDL2::SDL2main)
endif()

#include_directories(phi_desktop ${SDL2_INCLUDE_DIRS})
target_link_libraries(phi_desktop PRIVATE SDL2::SDL2)