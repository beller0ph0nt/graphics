#pragma once

#include <array>
#include <iostream>

#include "GL\glew.h"

#include "Vertex.h"

class VAORectangle {
public:
	VAORectangle(GLuint attribIndex = 0);
	~VAORectangle();
	void Draw() const;
private:
	GLuint m_attribIndex;
	GLuint m_vertexArrayObjectId;
	GLuint m_vertexBufferObjectId;
	GLuint m_elementBufferObjectId;
	std::array<Vertex, 4> m_vertexes{
		Vertex { -0.5f, -0.5f, 0.0f, 1.0f },
		Vertex { -0.5f,  0.5f, 0.0f, 1.0f },
		Vertex {  0.5f, -0.5f, 0.0f, 1.0f },
		Vertex {  0.5f,  0.5f, 0.0f, 1.0f }
	};
	std::array<GLuint, 6> m_indices{
		0, 1, 3,
		0, 3, 2
	};
};