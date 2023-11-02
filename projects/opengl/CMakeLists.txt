cmake_minimum_required(VERSION 3.15)

if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "CMAKE_BUILD_TYPE is empty")
endif()

string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" CMAKE_SYSTEM_PROCESSOR_LOWER)
string(TOLOWER "${CMAKE_SYSTEM_NAME}" CMAKE_SYSTEM_NAME_LOWER)
string(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_LOWER)

set(THIRD_PARTY_DIR third-party)
include_directories(
    ${THIRD_PARTY_DIR}/glew/include
    ${THIRD_PARTY_DIR}/glfw/include
)

add_compile_definitions(GLEW_STATIC)

set(LIBS_SUBPATH ${CMAKE_BUILD_TYPE_LOWER}/${CMAKE_SYSTEM_NAME_LOWER}/${CMAKE_SYSTEM_PROCESSOR_LOWER})
link_directories(
    ${THIRD_PARTY_DIR}/glew/lib/${LIBS_SUBPATH}
    ${THIRD_PARTY_DIR}/glfw/lib/${LIBS_SUBPATH}
)

add_subdirectory(opengl-abstraction-level)
add_subdirectory(1.1-setup-glfw)
add_subdirectory(1.2.1-simple-triangle)
add_subdirectory(1.2.2-simple-vao-triangle)
add_subdirectory(1.2.3-simple-ebo-rectangle)
add_subdirectory(1.2.4-simple-uniform-animation)
add_subdirectory(1.2.5-simple-fragment-interpolation)