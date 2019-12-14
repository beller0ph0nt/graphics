#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
	: ShaderProgram(move(VertexShader()), move(FragmentShader()))
{}
ShaderProgram::ShaderProgram(VertexShader&& vertexShader)
	: ShaderProgram(move(vertexShader), move(FragmentShader()))
{}
ShaderProgram::ShaderProgram(FragmentShader&& fragmentShader)
	: ShaderProgram(move(VertexShader()), move(fragmentShader))
{}

ShaderProgram::ShaderProgram(VertexShader&& vertexShader, FragmentShader&& fragmentShader)
{
	clog << "ShaderProgram::ctor" << endl;
	_id = glCreateProgram();
	glAttachShader(_id, vertexShader.GetId());
	glAttachShader(_id, fragmentShader.GetId());
	glLinkProgram(_id);
	GLint success;
	glGetProgramiv(_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLint len;
		glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &len);
		auto log = make_unique<char[]>(len);
		glGetProgramInfoLog(_id, len, NULL, log.get());
		throw exception(log.get());
	}
}

ShaderProgram::~ShaderProgram()
{
	clog << "~ShaderProgram::dtor" << endl;
	glDeleteProgram(_id);
}

GLuint ShaderProgram::GetId() const
{ 
	return _id; 
}
	
void ShaderProgram::Use() const
{ 
	glUseProgram(_id); 
}
