#pragma once

#include <string>
#include <iostream>

#include <GL\glew.h>

using namespace std;

class Shader
{
	GLuint _id;
	string _source;
public:
	Shader(GLenum type, string&& source);
	~Shader();
	GLuint GetId() const;
};