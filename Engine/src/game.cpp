#include "game.h"
 
#include "stb_image.h"

#include <iostream>


namespace engine
{
	Game* Game::INSTANCE {nullptr};

	Game& Game::GetInstance() {
		return *Game::INSTANCE;
	}

	void Game::Init() {
		stbi_set_flip_vertically_on_load(true);
		Window::Init();
		INSTANCE = new Game();
		INSTANCE->wnd.use();
		Renderer::Init();
	}

	void Game::Terminate() {
		delete INSTANCE;
		Window::Terminate();
	}

	void Game::updateTime() {
		double time = glfwGetTime();
		time_delta = time - time_last_frame;
		time_last_frame = time;
	}

	void Game::run(std::function<void (double)> GameLoop)
	{
		wnd.run([&] {
			updateTime();
			GameLoop(time_delta); // client gameloop

			// Update scene graph status
			scene->updateCoordsRecursive();
			auto nodes = scene->toSequence(); // serialized scene nodes

			// Run systems
			renderer.renderScene(nodes, *camera);
			animator.updateScene(nodes, time_delta);
		});
	}
}
