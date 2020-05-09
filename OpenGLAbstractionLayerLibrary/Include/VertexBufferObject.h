#pragma once

#include <vector>

#include <GL\glew.h>

#include "Vertex.h"

class VertexBufferObject {
public:
	VertexBufferObject(std::vector<Vertex>&& vertices);

	VertexBufferObject(VertexBufferObject&& object);
	VertexBufferObject(const VertexBufferObject& object) = delete;

	void operator=(VertexBufferObject&& object);
	void operator=(const VertexBufferObject& object) = delete;

	~VertexBufferObject();
private:
	GLuint m_id;
	std::vector<Vertex> m_vertices;
};