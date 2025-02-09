#include "game.h"
 
#include <iostream>


namespace engine
{
	Game* Game::instance_ {nullptr};

	Game& Game::GetInstance() {
		return *Game::instance_;
	}

	void Game::Init() {
		Window::Init();
		instance_ = new Game();
		instance_->wnd.use();
		Renderer::Init();
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
