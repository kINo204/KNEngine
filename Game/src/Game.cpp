#include "client.h"

#include <iostream>

using Game = engine::Game;

int main()
{
	Game::Init();
	Game& game = Game::GetInstance();

	engine::Scene scene;
	game.setScene(scene);

	engine::Sprite sprite;
	scene.addChild(sprite);

	game.run([] {

	});

	Game::Terminate();

	return 0;
}