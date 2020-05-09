#pragma once

#include <vector>

#include "VertexShader.h"
#include "FragmentShader.h"

class ShaderProgram {
public:
	ShaderProgram();
	ShaderProgram(VertexShader&& vertexShader);
	ShaderProgram(FragmentShader&& fragmentShader);
	ShaderProgram(VertexShader&& vertexShader, FragmentShader&& fragmentShader);
	ShaderProgram(std::vector<Shader>&& shaders);
	
	~ShaderProgram();
	
	GLuint GetId() const;
	void Use() const;
private:
	GLuint m_id;
};