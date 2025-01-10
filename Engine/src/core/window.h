#pragma once

#include "macros.h"
#include "GLFW/glfw3.h"


namespace engine
{
	class Window
	{

	/* Static */
	private:
		static GLFWmonitor* glfw_primary_monitor_; // Used for fullscreen mode.

	public:
		static void Init();
		static void Terminate();
	private:
		static void GlfwErrorCallback(int error, const char* description);


	/* Members */
	private:
		GLFWwindow* glfw_window_ = nullptr;

	public:
		Window();

	};
}
