#include "renderer.h"

namespace engine {
	void Renderer::renderScene(const Scene& scene) const {
		// TODO Render the scene.
		RenderSceneNode(scene);
	}

	void Renderer::RenderSceneNode(const SceneNode& node) {
		if (node.content)
			node.content->render();
		for (auto& child : node.children) {
			RenderSceneNode(child);
		}
	}
}