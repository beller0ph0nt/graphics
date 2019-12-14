#include "VertexShader.h"

VertexShader::VertexShader()
	: VertexShader(move(
		"#version 330 core\n"
		"layout (location = 0) in vec4 pos;\n"
		"void main() { gl_Position = pos; }\n"))
{}

VertexShader::VertexShader(string&& source)
	: Shader(GL_VERTEX_SHADER, move(source))
{
	clog << "VertexShader::ctor" << endl;
}

VertexShader::~VertexShader() 
{ 
	clog << "~VertexShader::dtor" << endl; 
}
