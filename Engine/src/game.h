#pragma once

#include "macros.h"

#include "core/window.h"
#include "core/scene.h"
#include "graphics/renderer.h"
#include "graphics/animator.h"

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
		Animator animator;
		Scene* scene = nullptr;
		Node camera = nullptr;

		Game() = default;
		void updateTime();

	public:
		void run(std::function<void (double)> GameLoop);

		double getDeltaTime() { return time_delta; }
		Scene& getScene() const { return *scene; }
		void setScene(Scene& scene) { this->scene = &scene; }
		void setCamera(Node node) { camera = node; }
		Camera& getCamera() { return *camera; }
	};
}
