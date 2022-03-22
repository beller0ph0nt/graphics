#include "SimpleTriangle.h"

void SimpleTriangle::Draw() const {
	glBegin(GL_TRIANGLES);
	glVertex2fv(m_vertexes[0]);
	glVertex2fv(m_vertexes[1]);
	glVertex2fv(m_vertexes[2]);
	glEnd();
}
