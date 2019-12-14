#include "FragmentShader.h"

FragmentShader::FragmentShader()
	: FragmentShader(move(
		"#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main() { fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); }\n"))
{}

FragmentShader::FragmentShader(string&& source)
	: Shader(GL_FRAGMENT_SHADER, move(source))
{
	clog << "FragmentShader::ctor" << endl;
}

FragmentShader::~FragmentShader()
{ 
	clog << "~FragmentShader::dtor" << endl;
}
