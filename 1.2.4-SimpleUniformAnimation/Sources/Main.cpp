#include <array>
#include <math.h>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <ShaderProgram.h>
#include <FragmentShader.h>

#include "VAORectangle.h"

using namespace std;

int main(void)
{
	try
	{
		GLFWwindow* window;

		if (!glfwInit())
			return -1;
		window = glfwCreateWindow(640, 480, "1.2.4-SimpleUniformAnimation", NULL, NULL);
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
		glfwSwapInterval(1);

		ShaderProgram customProgram(FragmentShader(
			"#version 330 core\n"
			"out vec4 fragColor;\n"
			"uniform vec4 externColor;"
			"void main() { fragColor = externColor; }\n"));
		GLint uniformLocation = glGetUniformLocation(customProgram.GetId(), "externColor");
		VAORectangle rectangle;

		glPointSize(5);
		glClearColor(0.0f, 0.2f, 0.0f, 1.0f);
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			customProgram.Use();
			float time = static_cast<float>(glfwGetTime());
			float redColor = sin(time) / 4.0f + 0.75f;
			glUniform4f(uniformLocation, 0.0f, redColor, 0.0f, 1.0f);
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
