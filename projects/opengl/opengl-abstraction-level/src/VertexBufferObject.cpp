#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(std::vector<Vertex>&& vertices)
    : m_vertices(move(vertices))
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

VertexBufferObject::VertexBufferObject(VertexBufferObject&& object) { }

void VertexBufferObject::operator=(VertexBufferObject&& object) { }

VertexBufferObject::~VertexBufferObject() { glDeleteBuffers(1, &m_id); }