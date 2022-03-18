#include "FragmentShader.h"

FragmentShader::FragmentShader() :
	FragmentShader(
		std::move(std::string(
			"#version 330 core\n"
			"out vec4 fragColor;\n"
			"void main() { fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f); }\n")
		)
	)
{}

FragmentShader::FragmentShader(std::string&& source)
	: Shader(Shader::Type::Fragment, move(source)) {
	std::clog << "FragmentShader::ctor(source) id=" << GetId() << std::endl;
}

FragmentShader::FragmentShader(fs::path&& filepath) :
	Shader(Shader::Type::Fragment, std::move(filepath)) {
	std::clog << "FragmentShader::ctor(filepath) id=" << GetId() << std::endl;
}

FragmentShader::FragmentShader(FragmentShader&& shader) :
	Shader(std::move(shader))
{}

void FragmentShader::operator=(FragmentShader&& shader) {
	Shader::operator=(std::move(shader));
}

FragmentShader::~FragmentShader() {
	std::clog << "~FragmentShader::dtor id=" << GetId() << std::endl;
}
