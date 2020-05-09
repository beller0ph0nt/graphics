#include "VertexShader.h"

VertexShader::VertexShader()
	: VertexShader(std::move(std::string(
		"#version 330 core\n"
		"layout (location = 0) in vec4 pos;\n"
		"void main() { gl_Position = pos; }\n")))
{}

VertexShader::VertexShader(std::string&& source)
	: Shader(Shader::Type::Vertex, move(source)) {
	std::clog << "VertexShader::ctor(source) id=" << GetId() << std::endl;
}

VertexShader::VertexShader(fs::path&& filepath)
	: Shader(Shader::Type::Vertex, std::move(filepath)) {
	std::clog << "VertexShader::ctor(filepath) id=" << GetId() << std::endl;
}

VertexShader::VertexShader(VertexShader&& shader)
	: Shader(std::move(shader))
{}

void VertexShader::operator=(VertexShader&& shader) {
	Shader::operator=(std::move(shader));
}

VertexShader::~VertexShader() {
	std::clog << "~VertexShader::dtor id=" << GetId() << std::endl;
}
