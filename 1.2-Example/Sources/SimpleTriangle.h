#pragma once

#include <GLFW/glfw3.h>

class SimpleTriangle
{
	const float vertexes[3][2] = {
		{ -0.5f, -0.5f },
		{  0.0f,  0.5f },
		{  0.5f, -0.5f }
	};
public:
	void Draw() const;
};