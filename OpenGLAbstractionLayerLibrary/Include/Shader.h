#pragma once

#include <string>
#include <iostream>
#include <experimental\filesystem>

#include <GL\glew.h>

#include "File.h"

class Shader {
public:
	enum class Type : GLenum {
		Unknown = 0,
		Compute = GL_COMPUTE_SHADER,
		Vertex = GL_VERTEX_SHADER,
		TessControl = GL_TESS_CONTROL_SHADER,
		TessEvaluation = GL_TESS_EVALUATION_SHADER,
		Geometry = GL_GEOMETRY_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	Shader(Type type, std::string&& source);
	Shader(Type type, fs::path&& filepath);
	
	Shader(Shader&& shader);
	void operator=(Shader&& shader);

	Shader(const Shader& shader) = delete;
	void operator=(const Shader& shader) = delete;
	
	virtual ~Shader();

	GLuint GetId() const;
private:
	GLuint m_id;
	Type m_type;
	std::string m_source;
};