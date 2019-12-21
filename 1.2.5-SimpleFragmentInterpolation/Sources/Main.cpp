#include <array>
#include <math.h>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Shader.h>
#include <ShaderProgram.h>
#include <FragmentShader.h>

#include "VAOTriangle.h"

using namespace std;

int main(void)
{
	try
	{
		GLFWwindow* window;

		if (!glfwInit())
			return -1;
		window = glfwCreateWindow(640, 480, "1.2.5-SimpleFragmentInterpolation", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		GLenum err = glewInit();
		if (GLEW_OK != err)
			cerr << "GLEW error: " << glewGetErrorString(err) << endl;

		cout << "glGetString:           " << glGetString(GL_VERSION) << endl;
		cout << "glfwGetVersionString:  " << glfwGetVersionString() << endl;
		cout << "glewGetString:         " << glewGetString(GLEW_VERSION) << endl;
		int maxVertexAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttributes);
		cout << "GL_MAX_VERTEX_ATTRIBS: " << maxVertexAttributes << endl;
		
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
		glfwSwapInterval(1);

		VertexShader vertexShader(move(string(
			"#version 330 core\n"
			"layout (location = 0) in vec4 position;\n"
			"layout (location = 1) in vec4 color;\n"
			"out vec4 fragColor;\n"
			"void main()\n"
			"{\n"
			"	gl_Position = position;\n"
			"	fragColor = color;\n"
			"}\n")));
		FragmentShader fragmentShader(move(string(
			"#version 330 core\n"
			"in vec4 fragColor;\n"
			"out vec4 FragColor;\n"
			"void main() { FragColor = fragColor; }\n")));

		vector<Shader> shaders;
		shaders.push_back(move(vertexShader));
		shaders.push_back(move(fragmentShader));

		ShaderProgram defaultProgram(move(shaders));
		VAOTriangle triangle;

		glPointSize(5);
		glClearColor(0.0f, 0.2f, 0.0f, 1.0f);
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			defaultProgram.Use();
			triangle.Draw();

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
