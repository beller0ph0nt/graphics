cmake_minimum_required(VERSION 3.15)

set(LOCAL_TARGET opengl-abstraction-level)

# todo: add header with definition for import, export
# add_compile_definitions(OGLAL_STATIC)

set(HEADERS
    src/Color.h
    src/File.h
    src/FragmentShader.h
    src/Image.h
    src/Position.h
    src/Shader.h
    src/ShaderProgram.h
    src/Vertex.h
    src/VertexBufferObject.h
    src/VertexShader.h
)

set(SOURCES
    src/File.cpp
    src/FragmentShader.cpp
    src/Image.cpp
    src/Shader.cpp
    src/ShaderProgram.cpp
    src/VertexBufferObject.cpp
    src/VertexShader.cpp
)

add_library(${LOCAL_TARGET} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${LOCAL_TARGET} PUBLIC src)

install(FILES ${HEADERS} DESTINATION include)
install(TARGETS ${LOCAL_TARGET} DESTINATION lib)