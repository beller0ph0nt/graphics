#include <iostream>

#include <GLFW/glfw3.h>

#include "SimpleTriangle.h"

using namespace std;

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "1.2.1-SimpleTriangle", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	cout << "glGetString: " << glGetString(GL_VERSION) << endl;
	cout << "glfwGetVersionString: " << glfwGetVersionString() << endl;

	SimpleTriangle triangle;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		triangle.Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
