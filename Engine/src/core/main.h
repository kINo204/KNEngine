#pragma once

#include "macros.h"

namespace engine
{
	ENGINE_API void Run();
	static void MainLoop();
	static void BeforeRun();
	static void AfterRun();
}
