#include "FragmentShader.h"

FragmentShader::FragmentShader() :
	FragmentShader(move(string(
		"#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main() { fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f); }\n")))
{}

FragmentShader::FragmentShader(string&& source) :
	Shader(Shader::Type::Fragment, move(source))
{
	clog << "FragmentShader::ctor(source) id=" << GetId() << endl;
}

FragmentShader::FragmentShader(fs::path&& filepath) :
	Shader(Shader::Type::Fragment, move(filepath))
{
	clog << "FragmentShader::ctor(filepath) id=" << GetId() << endl;
}

FragmentShader::FragmentShader(FragmentShader&& shader) :
	Shader(move(shader))
{}

void FragmentShader::operator=(FragmentShader&& shader)
{
	Shader::operator=(move(shader));
}

FragmentShader::~FragmentShader()
{ 
	clog << "~FragmentShader::dtor id=" << GetId() << endl;
}
