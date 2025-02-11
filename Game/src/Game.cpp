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
	auto& n1 = scene.addChild(sprite);
	auto& n2 = scene.addChild(sprite);

	game.run([&] {
		float trans_amount = 512 * game.getDeltaTime();
		n2.translate(trans_amount, trans_amount);
		float rot_amount = 90 * game.getDeltaTime();
		n2.rotate(rot_amount);
	});

	Game::Terminate();

	return 0;
}