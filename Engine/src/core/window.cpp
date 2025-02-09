#include "window.h"

#include "../graphics/renderer.h"

#include "glad/gl.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>


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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfw_primary_monitor_ = glfwGetPrimaryMonitor();
	}

	void Window::Terminate()
	{
		glfwTerminate();
	}

	Window::Window()
	{
		glfw_window_ = glfwCreateWindow(1024, 768, "Test Window", nullptr, nullptr);
		if (glfw_window_ == nullptr)
		{
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(-1);
		}
	}

	Window::~Window()
	{
		glfwDestroyWindow(this->glfw_window_);
	}

	void Window::use() {
		glfwMakeContextCurrent(glfw_window_);
		if (!gladLoadGL(glfwGetProcAddress)) throw std::runtime_error("Faild to load OpenGL!");
	}

	void Window::run(std::function<void()> MainLoop)
	{
		glViewport(0, 0, 1024, 768);
		glfwSwapInterval(1);
		while (!glfwWindowShouldClose(glfw_window_))
		{
			MainLoop();
			glfwSwapBuffers(glfw_window_);
			glfwPollEvents();
		}
	}

}
