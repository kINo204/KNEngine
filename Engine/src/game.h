#pragma once

#include "macros.h"

#include "core/window.h"
#include "graphics/scene.h"

namespace engine
{
	class ENGINE_API Game {
	private:
		static Game* instance_;

	public:
		static Game& GetInstance();
		static void Init();
		static void Terminate();

	private:
		Window wnd;
		Scene* scene = nullptr;

		Game();
		Game(const Game& game) = delete;
		Game& operator=(const Game& game) = delete;

	public:
		~Game();

		void run(std::function<void ()> GameLoop);

		Scene& getScene();
		void setScene(Scene& scene);
	};
}
