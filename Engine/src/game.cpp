#include "game.h"
#include <iostream>


namespace engine
{
	Game* Game::instance_ {nullptr};

	Game& Game::GetInstance() {
		if (instance_ == nullptr) {
			instance_ = new Game();
		}
		return *Game::instance_;
	}

	void Game::Init() {
		Window::Init();
	}

	void Game::Terminate() {
		delete instance_;
		Window::Terminate();
	}

	void Game::run(std::function<void ()> GameLoop)
	{
		wnd.run([&] {
			GameLoop();
			renderer.renderScene(*scene);
		});
	}

	Scene& Game::getScene() const {
		return *scene;
	}

	void Game::setScene(Scene& scene) {
		this->scene = &scene;
	}

}
