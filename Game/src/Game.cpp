#include "client.h"

#include <iostream>

using Game = engine::Game;

int main()
{
	Game::Init();
	Game& game = Game::GetInstance();
	game.run([] {
		// Game Loop
	});
	Game::Terminate();

	return 0;
}