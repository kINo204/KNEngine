#pragma once

#include "macros.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <functional>


namespace engine
{

	class Window
	{

	/* Static */
	private:
		static GLFWmonitor* GLFW_PRIMARY_MONITOR; // Used for fullscreen mode.

	public:
		static void Init();
		static void Terminate();
	private:
		static void GlfwErrorCallback(int error, const char* description);


	/* Members */
	private:
		GLFWwindow* glfw_window = nullptr;

	public:
		Window();
		Window(const Window& wnd) = delete; // non-copyable resource handle
		Window& operator=(const Window& wnd) = delete; // non-copyable resource handle
		//Window(Window&& wnd);
		//Window& operator=(Window&& wnd);
		~Window();

		void use();
		void run(std::function<void()> MainLoop);
	};

}
