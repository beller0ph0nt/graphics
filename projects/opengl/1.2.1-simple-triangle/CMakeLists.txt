cmake_minimum_required(VERSION 3.15)

set(LOCAL_TARGET 1.2.1-simple-triangle)

set(SOURCES 
    src/Main.cpp
    src/SimpleTriangle.cpp
    src/SimpleTriangle.h
)

add_executable(${LOCAL_TARGET} ${SOURCES})
target_link_libraries(${LOCAL_TARGET} PRIVATE
    $<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,opengl32,GL>
    glfw3
    opengl-abstraction-level
)

install(TARGETS ${LOCAL_TARGET} DESTINATION bin/opengl)