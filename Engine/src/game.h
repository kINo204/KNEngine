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
		double time_delta_ = 0.0, time_last_frame_ = 0.0;
		Window wnd_;
		Renderer renderer_;
		Scene* scene_ = nullptr;

		Game() = default;

	public:
		void run(std::function<void ()> GameLoop);

		void updateTime();
		double getDeltaTime() { return time_delta_; }
		Scene& getScene() const;
		void setScene(Scene& scene);
	};
}
