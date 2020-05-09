#pragma once

#include "Shader.h"

class FragmentShader : public Shader {
public:
	FragmentShader();
	FragmentShader(std::string&& source);
	FragmentShader(fs::path&& filepath);

	FragmentShader(FragmentShader&& shader);
	void operator=(FragmentShader&& shader);

	FragmentShader(const FragmentShader& shader) = delete;
	void operator=(const FragmentShader& shader) = delete;

	~FragmentShader();
};