#include "VAORectangle.h"

VAORectangle::VAORectangle(GLuint attribIndex) : m_attribIndex(attribIndex) {
	std::clog << "VAORectangle::ctor" << std::endl;
	glGenVertexArrays(1, &m_vertexArrayObjectId);
	glBindVertexArray(m_vertexArrayObjectId);
	glGenBuffers(1, &m_vertexBufferObjectId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjectId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertexes), m_vertexes.data(), GL_STATIC_DRAW);
	glGenBuffers(1, &m_elementBufferObjectId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObjectId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(m_attribIndex, sizeof(Position) / sizeof(float), GL_FLOAT,
		GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(m_attribIndex);
}

VAORectangle::~VAORectangle() {
	std::clog << "~VAORectangle::dtor" << std::endl;
	glDeleteBuffers(1, &m_elementBufferObjectId);
	glDeleteBuffers(1, &m_vertexBufferObjectId);
	glDeleteVertexArrays(1, &m_vertexArrayObjectId);
}

void VAORectangle::Draw() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObjectId);
	glBindVertexArray(m_vertexArrayObjectId);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_indices.size()), GL_UNSIGNED_INT, 0);
}
