#pragma once

#include <GLFW/glfw3.h>

class SimpleTriangle {
public:
	void Draw() const;
private:
	const float m_vertexes[3][2] = {
		{ -0.5f, -0.5f },
		{  0.0f,  0.5f },
		{  0.5f, -0.5f }
	};
};