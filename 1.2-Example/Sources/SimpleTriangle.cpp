#include "SimpleTriangle.h"

void SimpleTriangle::Draw() const
{
	glBegin(GL_TRIANGLES);
	glVertex2fv(vertexes[0]);
	glVertex2fv(vertexes[1]);
	glVertex2fv(vertexes[2]);
	glEnd();
}
