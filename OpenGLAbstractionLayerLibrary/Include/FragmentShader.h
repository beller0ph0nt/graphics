#pragma once

#include "Shader.h"

class FragmentShader : public Shader
{
public:
	FragmentShader();
	FragmentShader(string&& source);
	~FragmentShader();
};