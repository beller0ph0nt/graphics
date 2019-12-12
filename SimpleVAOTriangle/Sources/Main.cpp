#include <array>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

using namespace std;

struct Position
{
	float x;
	float y;
};

struct Vertex
{
	Position pos;
};

class VAOTriangle
{
	GLuint _attribIndex;
	GLuint _vertexArrayObjectId;
	GLuint _vertexBufferObjectId;
	array<Vertex, 3> _vertexes{
		Vertex { -0.9f, -0.5f },
		Vertex { -0.5f,  0.5f },
		Vertex { -0.1f, -0.5f }
	};
public:
	VAOTriangle(GLuint attribIndex = 0) : _attribIndex(attribIndex)
	{
		clog << "VAOTriangle::ctor" << endl;
		glGenVertexArrays(1, &_vertexArrayObjectId);
		glBindVertexArray(_vertexArrayObjectId);
		glGenBuffers(1, &_vertexBufferObjectId);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObjectId);
		glBufferData(GL_ARRAY_BUFFER, sizeof(_vertexes), _vertexes.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(_attribIndex, sizeof(Position) / sizeof(float), GL_FLOAT,
			GL_FALSE, sizeof(Vertex), 0);
		glEnableVertexAttribArray(_attribIndex);
	}

	~VAOTriangle()
	{
		clog << "~VAOTriangle::dtor" << endl;
		glDeleteBuffers(1, &_vertexBufferObjectId);
		glDeleteVertexArrays(1, &_vertexArrayObjectId);
	}

	void Draw() const
	{
		glBindVertexArray(_vertexArrayObjectId);
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(_vertexes.size()));
	}
};

class VAORectangle
{
	GLuint _attribIndex;
	GLuint _vertexArrayObjectId;
	GLuint _vertexBufferObjectId;
	GLuint _elementBufferObjectId;
	array<Vertex, 4> _vertexes{
		Vertex { 0.1f, -0.5f },
		Vertex { 0.1f,  0.5f },
		Vertex { 0.9f, -0.5f },
		Vertex { 0.9f,  0.5f }
	};
	array<GLuint, 6> _indices{
		0, 1, 3,
		0, 3, 2
	};
public:
	VAORectangle(GLuint attribIndex = 0) : _attribIndex(attribIndex)
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

	~VAORectangle()
	{
		clog << "~VAORectangle::dtor" << endl;
		glDeleteBuffers(1, &_elementBufferObjectId);
		glDeleteBuffers(1, &_vertexBufferObjectId);
		glDeleteVertexArrays(1, &_vertexArrayObjectId);
	}

	void Draw() const
	{
		glBindVertexArray(_vertexArrayObjectId);
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_indices.size()), GL_UNSIGNED_INT, 0);
	}
};

class Shader
{
	GLuint _id;
	string _source;
public:
	Shader(GLenum type, string&& source)
	{
		clog << "Shader::ctor" << endl;
		_id = glCreateShader(type);
		_source = source;
		const char* src = _source.c_str();
		glShaderSource(_id, 1, &src, NULL);
		glCompileShader(_id);
		GLint success;
		glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			GLint len;
			glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &len);
			auto log = make_unique<char[]>(len);
			glGetShaderInfoLog(_id, len, NULL, log.get());
			throw exception(log.get());
		}
	}

	~Shader()
	{ 
		clog << "~Shader::dtor" << endl;
		glDeleteShader(_id); 
	}

	GLuint GetId() const { return _id; }
};

class VertexShader : public Shader
{
public:
	VertexShader() : VertexShader(move(
		"#version 330 core\n"
		"layout (location = 0) in vec4 pos;\n"
		"void main() { gl_Position = pos; }\n"))
	{}

	VertexShader(string&& source) : Shader(GL_VERTEX_SHADER, move(source))
	{ clog << "VertexShader::ctor" << endl; }

	~VertexShader() { clog << "~VertexShader::dtor" << endl; }
};

class FragmentShader : public Shader
{
public:
	FragmentShader() : FragmentShader(move(
		"#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main() { fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); }\n"))
	{}

	FragmentShader(string&& source) : Shader(GL_FRAGMENT_SHADER, move(source))
	{ clog << "FragmentShader::ctor" << endl; }

	~FragmentShader() { clog << "~FragmentShader::dtor" << endl; }
};

class ShaderProgram
{
	GLuint _id;
public:
	ShaderProgram() :
		ShaderProgram(move(VertexShader()), move(FragmentShader()))
	{}
	ShaderProgram(VertexShader&& vertexShader) :
		ShaderProgram(move(vertexShader), move(FragmentShader()))
	{}
	ShaderProgram(FragmentShader&& fragmentShader) :
		ShaderProgram(move(VertexShader()), move(fragmentShader))
	{}

	ShaderProgram(VertexShader&& vertexShader, FragmentShader&& fragmentShader)
	{
		clog << "ShaderProgram::ctor" << endl;
		_id = glCreateProgram();
		glAttachShader(_id, vertexShader.GetId());
		glAttachShader(_id, fragmentShader.GetId());
		glLinkProgram(_id);
		GLint success;
		glGetProgramiv(_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			GLint len;
			glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &len);
			auto log = make_unique<char[]>(len);
			glGetProgramInfoLog(_id, len, NULL, log.get());
			throw exception(log.get());
		}
	}

	~ShaderProgram() 
	{ 
		clog << "~ShaderProgram::dtor" << endl;
		glDeleteProgram(_id);
	}

	GLuint GetId() const { return _id; }
	void Use() const { glUseProgram(_id); }
};

int main(void)
{
	try
	{
		GLFWwindow* window;

		if (!glfwInit())
			return -1;
		window = glfwCreateWindow(640, 480, "1.2.1-SimpleVAOTriangle", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		GLenum err = glewInit();
		if (GLEW_OK != err)
			cerr << "GLEW error: " << glewGetErrorString(err) << endl;

		cout << "glGetString:          " << glGetString(GL_VERSION) << endl;
		cout << "glfwGetVersionString: " << glfwGetVersionString() << endl;
		cout << "glewGetString:        " << glewGetString(GLEW_VERSION) << endl;
		
		auto keyCallback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS)
				if (key == GLFW_KEY_ESCAPE)
					glfwSetWindowShouldClose(window, true);
				else if (key == GLFW_KEY_1)
					glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
				else if (key == GLFW_KEY_2)
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				else if (key == GLFW_KEY_3)
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		};
		glfwSetKeyCallback(window, keyCallback);

		ShaderProgram defaultProgram;
		ShaderProgram customProgram(FragmentShader(
			"#version 330 core\n"
			"out vec4 fragColor;\n"
			"void main() { fragColor = vec4(0.0f, 0.5f, 0.2f, 1.0f); }\n"));

		VAOTriangle triangle;
		VAORectangle rectangle;

		glPointSize(5);
		glClearColor(0.0f, 0.2f, 0.0f, 1.0f);
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			defaultProgram.Use();
			triangle.Draw();

			customProgram.Use();
			rectangle.Draw();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
	}
	catch (exception ex)
	{
		cerr << ex.what() << endl;
		cin.get();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
