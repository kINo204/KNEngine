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
	engine::Node n1 = scene.addChild(sprite);
	engine::Node n2 = n1->addChild(sprite);
	n2->rotate(45);
	//engine::Node camera = scene.addChild();
	engine::Node camera = scene.addChild();
	game.setCamera(camera);

	game.run([&] {
		float trans_amount = 512 * game.getDeltaTime();
		n1->translate(trans_amount, trans_amount);
		float rot_amount = 90 * game.getDeltaTime();
		n1->rotate(rot_amount);
	});

	Game::Terminate();

	return 0;
}