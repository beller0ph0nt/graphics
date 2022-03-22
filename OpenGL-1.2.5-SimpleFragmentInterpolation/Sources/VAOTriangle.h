#pragma once

#include <array>
#include <iostream>

#include <GL\glew.h>

#include <Vertex.h>

class VAOTriangle {
public:
	VAOTriangle();
	~VAOTriangle();
	void Draw() const;
private:
	GLuint m_vertexArrayObjectId;
	GLuint m_vertexBufferObjectId;
	std::array<Vertex, 3> m_vertexes{
		Vertex { Position { -0.5f, -0.5f, 0.0f, 1.0f }, Color { 1.0f, 0.0f, 0.0f, 1.0f } },
		Vertex { Position {  0.0f,  0.5f, 0.0f, 1.0f }, Color { 0.0f, 1.0f, 0.0f, 1.0f } },
		Vertex { Position {  0.5f, -0.5f, 0.0f, 1.0f }, Color { 0.0f, 0.0f, 1.0f, 1.0f } }
	};
};