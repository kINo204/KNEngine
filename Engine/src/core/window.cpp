#include "window.h"

#include <iostream>


namespace engine
{

	GLFWmonitor* Window::glfw_primary_monitor_ = nullptr;

	void Window::GlfwErrorCallback(int error, const char* description)
	{
		fprintf(stderr, "GLFW Error: %s\n", description);
	}

	void Window::Init()
	{
		glfwSetErrorCallback(GlfwErrorCallback);
		glfwInit();
		glfw_primary_monitor_ = glfwGetPrimaryMonitor();
	}

	void Window::Terminate()
	{
		glfwTerminate();
	}

	Window::Window()
	{
		glfw_window_ = glfwCreateWindow(1024, 768, "Window Name", glfw_primary_monitor_, nullptr);
	}

}
