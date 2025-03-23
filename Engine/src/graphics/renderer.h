#pragma once

#include "scene.h"
#include "rendering_api/shader.h"

#include <memory>


namespace engine {

	class Renderer {
	public:
		// Define default shaders.
		static std::shared_ptr<Shader> SHADER_SPRITE_DEFAULT;
		static void Init();

		void renderScene(Scene& scene);
	};

}
