#include "renderer.h"

#include "glm/gtc/matrix_transform.hpp"


namespace engine {

	std::shared_ptr<Shader> Renderer::SHADER_SPRITE_DEFAULT = nullptr;

	void Renderer::Init() {
		Renderer::SHADER_SPRITE_DEFAULT = std::make_shared<Shader>(
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"uniform mat4x4 proj;\n"
			"uniform mat4x4 model;\n"
			"uniform mat4x4 anchor;\n"
			"void main() {\n"
			"gl_Position = proj * model * anchor * vec4(vec3(aPos), 1.0);\n"
			"}\n",
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main() {\n"
			"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n"
		);
	}

	void Renderer::renderScene(Scene& scene) {
		// Update nodes' model transitions.
		scene.updateModelTransRecursive();

		// TODO Register a camera.
		// TODO Build ortho matrix.
		glm::mat4 proj = glm::ortho(0.f, 4000.f, 0.f, 3000.f);

		// Sort renderable objects by shader programs.
		std::vector<SceneNode*> sequence;
		sequence.push_back(&scene);
		for (int i = 0; i < sequence.size(); i++) {
			for (auto& child : sequence[i]->children)
				sequence.push_back(&child);
		}

		for (auto node : sequence) {
			node->render(proj);
		}
	}

}