#include "main.h"

#include "window.h"


namespace engine
{
	ENGINE_API void Run()
	{
		Window::Init();
		Window::Terminate();
	}
}
