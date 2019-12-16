#pragma once

#include <string>
#include <iostream>
#include <experimental\filesystem>

#include <GL\glew.h>

#include "File.h"

using namespace std;

class Shader
{
	GLuint _id;
	string _source;
public:
	Shader(GLenum type, string&& source);
	Shader(GLenum type, fs::path&& filepath);
	~Shader();
	GLuint GetId() const;
};