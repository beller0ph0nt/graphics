#include "Shader.h"

Shader::Shader(GLenum type, string&& source)
{
	clog << "Shader::ctor" << endl;
	_id = glCreateShader(type);
	_source = source;
	const char* src = _source.c_str();
	glShaderSource(_id, 1, &src, NULL);
	glCompileShader(_id);
	GLint success;
	glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLint len;
		glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &len);
		auto log = make_unique<char[]>(len);
		glGetShaderInfoLog(_id, len, NULL, log.get());
		throw exception(log.get());
	}
}

Shader::Shader(GLenum type, fs::path&& filepath)
	: Shader(type, move(File::ReadAll(move(filepath))))
{}

Shader::~Shader()
{
	clog << "~Shader::dtor" << endl;
	glDeleteShader(_id);
}

GLuint Shader::GetId() const
{ 
	return _id; 
}
