#pragma once

#include "scene.h"

namespace engine {
	class Renderer {
	public:
		static void RenderSceneNode(const SceneNode& node);
		void renderScene(const Scene& scene) const;
	};
}
