#pragma once

#include "macros.h"

#include "core/window.h"
#include "graphics/renderer.h"
#include "graphics/scene.h"

namespace engine
{
	class ENGINE_API Game {
	private:
		static Game* INSTANCE;

	public:
		static Game& GetInstance();
		static void Init();
		static void Terminate();

	private:
		double time_delta = 0.0, time_last_frame = 0.0;
		Window wnd;
		Renderer renderer;
		Scene* scene = nullptr;
		Node camera = nullptr;

		Game() = default;

	public:
		void run(std::function<void ()> GameLoop);

		void updateTime();
		double getDeltaTime() { return time_delta; }
		Scene& getScene() const { return *scene; }
		void setScene(Scene& scene) { this->scene = &scene; }
		void setCamera(Node node) { camera = node; }
		Camera& getCamera() { return *camera; }
	};
}
