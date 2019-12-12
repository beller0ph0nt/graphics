#include <iostream>

#include <GLFW/glfw3.h>

using namespace std;

class SimpleTriangle
{
	const float vertexes[3][2] = {
		{ -0.5f, -0.5f },
		{  0.0f,  0.5f },
		{  0.5f, -0.5f }
	};
public:
	void Draw()
	{
		glBegin(GL_TRIANGLES);
		glVertex2fv(vertexes[0]);
		glVertex2fv(vertexes[1]);
		glVertex2fv(vertexes[2]);
		glEnd();
	}
};

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
