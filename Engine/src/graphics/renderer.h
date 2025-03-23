#pragma once

#include "scene.h"
#include "rendering_api/shader.h"

#include <memory>


namespace engine {

	class Renderer {
		// Define default shaders.
	public:
		static std::shared_ptr<Shader> SHADER_SPRITE_DEFAULT;
		static void Init();

		void renderScene(Scene& scene);
	};

}
