#include "VertexShader.h"

VertexShader::VertexShader()
	: VertexShader(move(string(
		"#version 330 core\n"
		"layout (location = 0) in vec4 pos;\n"
		"void main() { gl_Position = pos; }\n")))
{}

VertexShader::VertexShader(string&& source)
	: Shader(Shader::Type::Vertex, move(source))
{
	clog << "VertexShader::ctor(source) id=" << GetId() << endl;
}

VertexShader::VertexShader(fs::path&& filepath)
	: Shader(Shader::Type::Vertex, move(filepath))
{
	clog << "VertexShader::ctor(filepath) id=" << GetId() << endl;
}

VertexShader::VertexShader(VertexShader&& shader)
	: Shader(move(shader))
{}

void VertexShader::operator=(VertexShader&& shader)
{
	Shader::operator=(move(shader));
}

VertexShader::~VertexShader() 
{ 
	clog << "~VertexShader::dtor id=" << GetId() << endl;
}
