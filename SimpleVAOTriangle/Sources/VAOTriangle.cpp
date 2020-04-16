#include "VAOTriangle.h"

VAOTriangle::VAOTriangle(GLuint attribIndex) : m_attribIndex(attribIndex)
{
	clog << "VAOTriangle::ctor" << endl;
	glGenVertexArrays(1, &m_vertexArrayObjectId);
	glBindVertexArray(m_vertexArrayObjectId);
	glGenBuffers(1, &m_vertexBufferObjectId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjectId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertexes), m_vertexes.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(m_attribIndex, sizeof(Position) / sizeof(float), GL_FLOAT,
		GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(m_attribIndex);
}

VAOTriangle::~VAOTriangle()
{
	clog << "~VAOTriangle::dtor" << endl;
	glDeleteBuffers(1, &m_vertexBufferObjectId);
	glDeleteVertexArrays(1, &m_vertexArrayObjectId);
}

void VAOTriangle::Draw() const
{
	glBindVertexArray(m_vertexArrayObjectId);
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertexes.size()));
}