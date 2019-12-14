#pragma once

#include "VertexShader.h"
#include "FragmentShader.h"

class ShaderProgram
{
	GLuint _id;
public:
	ShaderProgram();
	ShaderProgram(VertexShader&& vertexShader);
	ShaderProgram(FragmentShader&& fragmentShader);
	ShaderProgram(VertexShader&& vertexShader, FragmentShader&& fragmentShader);
	~ShaderProgram();
	GLuint GetId() const;
	void Use() const;
};