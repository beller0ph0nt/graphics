#pragma once

#include <array>
#include <iostream>

#include "GL\glew.h"

#include "Vertex.h"

class VAOTriangle {
public:
	VAOTriangle(GLuint attribIndex = 0);
	~VAOTriangle();
	void Draw() const;
private:
	GLuint m_attribIndex;
	GLuint m_vertexArrayObjectId;
	GLuint m_vertexBufferObjectId;
	std::array<Vertex, 3> m_vertexes {
		Vertex { -0.5f, -0.5f, 0.0f, 1.0f },
		Vertex {  0.0f,  0.5f, 0.0f, 1.0f },
		Vertex {  0.5f, -0.5f, 0.0f, 1.0f }
	};
};