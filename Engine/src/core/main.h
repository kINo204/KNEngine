#pragma once

#include "macros.h"

#include "window.h"
#include <memory>

namespace engine
{
	class ENGINE_API Game {
	private:
		static std::unique_ptr<Game> instance_;

	public:
		static Game& GetInstance();
		static void Init();
		static void Terminate();

	private:
		Window wnd;
		Game();
		Game(const Game& game) = delete;
		Game& operator=(const Game& game) = delete;

	public:
		~Game();
		void run(std::function<void ()> GameLoop);
	};
}
