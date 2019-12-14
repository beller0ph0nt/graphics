#pragma once

#include <array>
#include <iostream>

#include "GL\glew.h"

#include "Vertex.h"

using namespace std;

class VAORectangle
{
	GLuint _attribIndex;
	GLuint _vertexArrayObjectId;
	GLuint _vertexBufferObjectId;
	GLuint _elementBufferObjectId;
	array<Vertex, 4> _vertexes{
		Vertex { -0.5f, -0.5f, 0.0f, 1.0f },
		Vertex { -0.5f,  0.5f, 0.0f, 1.0f },
		Vertex {  0.5f, -0.5f, 0.0f, 1.0f },
		Vertex {  0.5f,  0.5f, 0.0f, 1.0f }
	};
	array<GLuint, 6> _indices{
		0, 1, 3,
		0, 3, 2
	};
public:
	VAORectangle(GLuint attribIndex = 0);
	~VAORectangle();
	void Draw() const;
};