#include "window.h"

#include <iostream>

#include "glad/gl.h"


namespace engine
{

	void Window::GlfwErrorCallback(int error, const char* description)
	{
		fprintf(stderr, "GLFW Error: %s\n", description);
		glfwTerminate();
		exit(-1);
	}

	GLFWmonitor* Window::glfw_primary_monitor_ = nullptr;

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
		glfw_window_ = glfwCreateWindow(1024, 768, "Test Window", nullptr, nullptr);
	}

	Window::~Window()
	{
		glfwDestroyWindow(this->glfw_window_);
	}

	void Window::run(std::function<void()> MainLoop)
	{
		GLFWwindow* wnd = this->glfw_window_;
		glfwMakeContextCurrent(wnd);
		gladLoadGL(glfwGetProcAddress);
		glfwSwapInterval(1);

		while (!glfwWindowShouldClose(wnd))
		{
			MainLoop();
			glfwSwapBuffers(wnd);
			glfwPollEvents();
		}
	}

}
