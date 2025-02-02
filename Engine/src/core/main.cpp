#include "main.h"

#include "window.h"


namespace engine
{
	ENGINE_API void Run()
	{
		BeforeRun();

		{ // Brace for RAII.
			Window main_window;

			main_window.run([]{
				// Main window loop.
			}); 
		}

		AfterRun();
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
