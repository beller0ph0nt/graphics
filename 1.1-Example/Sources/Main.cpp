#include <iostream>

#include <GLFW/glfw3.h>

using namespace std;

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "1.1-SetupGLFW", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	cout << "glGetString: " << glGetString(GL_VERSION) << endl;
	cout << "glfwGetVersionString: " << glfwGetVersionString() << endl;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
