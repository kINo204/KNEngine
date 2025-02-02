#include "main.h"
#include <iostream>


namespace engine
{
	std::unique_ptr<Game> Game::instance_ {nullptr};

	Game& Game::GetInstance() {
		if (instance_ == nullptr) {
			instance_.reset(new Game());
		}
		return *Game::instance_;
	}

	void Game::Init() {
		Window::Init();
	}

	void Game::Terminate() {
		delete instance_.release();
		Window::Terminate();
	}

	Game::Game() {
		std::cout << "Creating Game" << std::endl;
	}

	void Game::run(std::function<void ()> GameLoop)
	{
		wnd.run([&] {
			GameLoop();
		});
	}

	Game::~Game() {
		std::cout << "Destroying Game" << std::endl;
	}

}
