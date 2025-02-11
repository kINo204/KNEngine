#include "game.h"
 
#include <iostream>


namespace engine
{
	Game* Game::INSTANCE {nullptr};

	Game& Game::GetInstance() {
		return *Game::INSTANCE;
	}

	void Game::Init() {
		Window::Init();
		INSTANCE = new Game();
		INSTANCE->wnd.use();
		Renderer::Init();
	}

	void Game::Terminate() {
		delete INSTANCE;
		Window::Terminate();
	}

	void Game::run(std::function<void ()> GameLoop)
	{
		wnd.run([&] {
			updateTime();
			GameLoop();
			renderer.renderScene(*scene);
		});
	}

	void Game::updateTime() {
		double time = glfwGetTime();
		time_delta = time - time_last_frame;
		time_last_frame = time;
	}
}
