#include "renderer.h"

namespace engine {

	void Renderer::renderScene(const Scene& scene) const {
		// Register a camera.

		// Sort renderable objects by shader programs.
		renderNode(scene);
	}

	void Renderer::renderNode(const SceneNode& node) const {

	}

}