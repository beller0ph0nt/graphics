#pragma once

#include <array>
#include <iostream>

#include "GL\glew.h"

#include "Vertex.h"

using namespace std;

class VAOTriangle
{
	GLuint _attribIndex;
	GLuint _vertexArrayObjectId;
	GLuint _vertexBufferObjectId;
	array<Vertex, 3> _vertexes{
		Vertex { -0.5f, -0.5f, 0.0f, 1.0f },
		Vertex {  0.0f,  0.5f, 0.0f, 1.0f },
		Vertex {  0.5f, -0.5f, 0.0f, 1.0f }
	};
public:
	VAOTriangle(GLuint attribIndex = 0);
	~VAOTriangle();
	void Draw() const;
};