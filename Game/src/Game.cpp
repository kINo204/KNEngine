#include "client.h"

#include <iostream>

using Game = engine::Game;

int main()
{
	Game::Init();
	Game& game = Game::GetInstance();

	engine::Scene scene;
	game.setScene(scene);

	//engine::Sprite s{ "sprite.png" };
	engine::Animation s{"sprite.png", 10, 2, 1.0};
	s.play(); s.should_loop = true;
	engine::Node n1 = scene.addChild(s);
	engine::Node camera = scene.addChild();
	game.setCamera(camera);

	game.run([&](double delta_time) {
		//float trans_amount = 512 * delta_time;
		//n1->translate(trans_amount, trans_amount);
		//float rot_amount = 90 * delta_time;
		//n1->rotate(rot_amount);
	});

	Game::Terminate();

	return 0;
}