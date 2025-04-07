#pragma once

#include "core/scene.h"

#include <memory>


namespace engine {

	class Renderer {
	public:
		static void Init();

		void renderScene(Scene& scene);
	};

}
