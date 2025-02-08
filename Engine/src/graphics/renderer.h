#pragma once

#include "scene.h"

namespace engine {
	class Renderer {
	private:
		void renderNode(const SceneNode& node) const;

	public:
		void renderScene(const Scene& scene) const;
	};
}
