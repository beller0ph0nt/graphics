#include "VAOTriangle.h"

VAOTriangle::VAOTriangle(GLuint attribIndex) : _attribIndex(attribIndex)
{
	clog << "VAOTriangle::ctor" << endl;
	glGenVertexArrays(1, &_vertexArrayObjectId);
	glBindVertexArray(_vertexArrayObjectId);
	glGenBuffers(1, &_vertexBufferObjectId);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObjectId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertexes), _vertexes.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(_attribIndex, sizeof(Position) / sizeof(float), GL_FLOAT,
		GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(_attribIndex);
}

VAOTriangle::~VAOTriangle()
{
	clog << "~VAOTriangle::dtor" << endl;
	glDeleteBuffers(1, &_vertexBufferObjectId);
	glDeleteVertexArrays(1, &_vertexArrayObjectId);
}

void VAOTriangle::Draw() const
{
	glBindVertexArray(_vertexArrayObjectId);
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(_vertexes.size()));
}