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

int main(void) {
	try {
		GLFWwindow* window;

		if (!glfwInit()) {
			return -1;
		}

		window = glfwCreateWindow(640, 480, "OpenGL-1.2.4-SimpleUniformAnimation", NULL, NULL);
		if (!window) {
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		GLenum err = glewInit();
		if (GLEW_OK != err) {
			std::cerr << "GLEW error: " << glewGetErrorString(err) << std::endl;
		}

		std::cout << "glGetString:          " << glGetString(GL_VERSION) << std::endl;
		std::cout << "glfwGetVersionString: " << glfwGetVersionString() << std::endl;
		std::cout << "glewGetString:        " << glewGetString(GLEW_VERSION) << std::endl;

		glfwSetKeyCallback(
			window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods) {
				if (action == GLFW_PRESS) {
					if (key == GLFW_KEY_ESCAPE) {
						glfwSetWindowShouldClose(window, true);
					} else if (key == GLFW_KEY_1) {
						glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
					} else if (key == GLFW_KEY_2) {
						glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
					} else if (key == GLFW_KEY_3) {
						glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					}
				}
			}
		);
		glfwSwapInterval(1);

		ShaderProgram customProgram(FragmentShader(std::move(std::string(
			"#version 330 core\n"
			"out vec4 fragColor;\n"
			"uniform vec4 externColor;"
			"void main() { fragColor = externColor; }\n"))));
		GLint uniformLocation = glGetUniformLocation(customProgram.GetId(), "externColor");
		VAORectangle rectangle;

		glPointSize(5);
		glClearColor(0.0f, 0.2f, 0.0f, 1.0f);
		while (!glfwWindowShouldClose(window)) {
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
	} catch (std::exception ex) {
		std::cerr << ex.what() << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
