#include "VAOTriangle.h"

VAOTriangle::VAOTriangle() {
	std::clog << "VAOTriangle::ctor" << std::endl;
	glGenVertexArrays(1, &m_vertexArrayObjectId);
	glBindVertexArray(m_vertexArrayObjectId);

	glGenBuffers(1, &m_vertexBufferObjectId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjectId);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(m_vertexes),
		m_vertexes.data(),
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(
		0,
		sizeof(Position) / sizeof(float),
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		0
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,
		sizeof(Color) / sizeof(float),
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		reinterpret_cast<const void*>(offsetof(Vertex, color))
	);
	glEnableVertexAttribArray(1);
}

VAOTriangle::~VAOTriangle() {
	std::clog << "~VAOTriangle::dtor" << std::endl;
	glDeleteBuffers(1, &m_vertexBufferObjectId);
	glDeleteVertexArrays(1, &m_vertexArrayObjectId);
}

void VAOTriangle::Draw() const {
	glBindVertexArray(m_vertexArrayObjectId);
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertexes.size()));
}