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
	vector<Shader> shaders;
	shaders.push_back(move(vertexShader));
	shaders.push_back(move(fragmentShader));
	ShaderProgram(move(shaders));
}

ShaderProgram::ShaderProgram(vector<Shader>&& shaders)
{
	m_id = glCreateProgram();
	clog << "ShaderProgram::ctor id=" << m_id << endl;
	for (int i = 0; i < shaders.size(); i++)
	{
		glAttachShader(m_id, shaders[i].GetId());
	}
	glLinkProgram(m_id);
	GLint success;
	glGetProgramiv(m_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLint len;
		glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &len);
		auto log = make_unique<char[]>(len);
		glGetProgramInfoLog(m_id, len, NULL, log.get());
		throw exception(log.get());
	}
}

ShaderProgram::~ShaderProgram()
{
	clog << "~ShaderProgram::dtor id=" << m_id << endl;
	glDeleteProgram(m_id);
}

GLuint ShaderProgram::GetId() const
{ 
	return m_id; 
}
	
void ShaderProgram::Use() const
{ 
	glUseProgram(m_id); 
}
