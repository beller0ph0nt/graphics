#pragma once

#include "Shader.h"

class VertexShader : public Shader {
public:
    VertexShader();
    VertexShader(std::string&& source);
    VertexShader(fs::path&& filepath);

    VertexShader(VertexShader&& shader);
    void operator=(VertexShader&& shader);

    VertexShader(const VertexShader& shader) = delete;
    void operator=(const VertexShader& shader) = delete;

    ~VertexShader();
};