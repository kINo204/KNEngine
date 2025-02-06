#pragma once

#include "macros.h"

#include "core/window.h"
#include "graphics/renderer.h"
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
		Renderer renderer;
		Scene* scene = nullptr;

		Game() = default;

	public:
		void run(std::function<void ()> GameLoop);

		Scene& getScene() const;
		void setScene(Scene& scene);
	};
}
