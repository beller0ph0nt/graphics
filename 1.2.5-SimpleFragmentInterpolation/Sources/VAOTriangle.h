#pragma once

#include <array>
#include <iostream>

#include <GL\glew.h>

#include <Vertex.h>

using namespace std;

class VAOTriangle
{
	GLuint _vertexArrayObjectId;
	GLuint _vertexBufferObjectId;
	array<Vertex, 3> _vertexes{
		Vertex { Position { -0.5f, -0.5f, 0.0f, 1.0f }, Color { 1.0f, 0.0f, 0.0f, 1.0f } },
		Vertex { Position {  0.0f,  0.5f, 0.0f, 1.0f }, Color { 0.0f, 1.0f, 0.0f, 1.0f } },
		Vertex { Position {  0.5f, -0.5f, 0.0f, 1.0f }, Color { 0.0f, 0.0f, 1.0f, 1.0f } }
	};
public:
	VAOTriangle();
	~VAOTriangle();
	void Draw() const;
};