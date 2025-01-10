#include "main.h"

#include "window.h"


namespace engine
{
	ENGINE_API void Run()
	{
		BeforeRun();

		// Run the main game window.
		{
			Window main_window;
			main_window.run(MainLoop);
		}

		AfterRun();
	}

	static void MainLoop()
	{

	}

	static void BeforeRun()
	{
		Window::Init();
	}

	static void AfterRun()
	{
		Window::Terminate();
	}

}
