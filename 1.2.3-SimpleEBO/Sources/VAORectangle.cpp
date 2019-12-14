#include "VAORectangle.h"

VAORectangle::VAORectangle(GLuint attribIndex) : _attribIndex(attribIndex)
{
	clog << "VAORectangle::ctor" << endl;
	glGenVertexArrays(1, &_vertexArrayObjectId);
	glBindVertexArray(_vertexArrayObjectId);
	glGenBuffers(1, &_vertexBufferObjectId);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObjectId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertexes), _vertexes.data(), GL_STATIC_DRAW);
	glGenBuffers(1, &_elementBufferObjectId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObjectId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(_attribIndex, sizeof(Position) / sizeof(float), GL_FLOAT,
		GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(_attribIndex);
}

VAORectangle::~VAORectangle()
{
	clog << "~VAORectangle::dtor" << endl;
	glDeleteBuffers(1, &_elementBufferObjectId);
	glDeleteBuffers(1, &_vertexBufferObjectId);
	glDeleteVertexArrays(1, &_vertexArrayObjectId);
}

void VAORectangle::Draw() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObjectId);
	glBindVertexArray(_vertexArrayObjectId);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_indices.size()), GL_UNSIGNED_INT, 0);
}
