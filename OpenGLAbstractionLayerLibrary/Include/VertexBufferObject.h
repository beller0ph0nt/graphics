#pragma once

#include <vector>

#include <GL\glew.h>

#include "Vertex.h"

using namespace std;

class VertexBufferObject
{
public:
	VertexBufferObject(vector<Vertex>&& vertices);

	VertexBufferObject(VertexBufferObject&& object);
	VertexBufferObject(const VertexBufferObject& object) = delete;

	void operator=(VertexBufferObject&& object);
	void operator=(const VertexBufferObject& object) = delete;

	~VertexBufferObject();
private:
	GLuint m_id;
	vector<Vertex> m_vertices;
};