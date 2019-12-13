#pragma once

#include "VertexShader.h"
#include "FragmentShader.h"

class ShaderProgram
{
	GLuint _id;
public:
	ShaderProgram();/* :
		ShaderProgram(move(VertexShader()), move(FragmentShader()))
	{}*/
	ShaderProgram(VertexShader&& vertexShader);/* :
		ShaderProgram(move(vertexShader), move(FragmentShader()))
	{}*/
	ShaderProgram(FragmentShader&& fragmentShader);/* :
		ShaderProgram(move(VertexShader()), move(fragmentShader))
	{}*/

	ShaderProgram(VertexShader&& vertexShader, FragmentShader&& fragmentShader);/*
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
	}*/

	~ShaderProgram();/*
	{
		clog << "~ShaderProgram::dtor" << endl;
		glDeleteProgram(_id);
	}*/

	GLuint GetId() const;/* { return _id; }*/
	void Use() const;/* { glUseProgram(_id); }*/
};