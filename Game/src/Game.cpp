#include "client.h"

#include <iostream>

using Game = engine::Game;

int main()
{
	Game::Init();
	Game& game = Game::GetInstance();

	engine::Scene scene;
	game.setScene(scene);

	engine::Sprite sprite{"wall.jpg"};
	// May create multiple sprites of the same content.
	auto& node = scene.addChild(sprite);
	node.translate(800, 1000);
	node.rotate(45);
	node.translate(1600, 0);
	node.rotate(25);
	node.translate(400, 200);

	game.run([] {

	});

	Game::Terminate();

	return 0;
}