#include "renderer.h"

#include "utils/shader.h"

#include "glm/gtc/matrix_transform.hpp"


namespace engine {

	void Renderer::Init() {
		Shader::SHADER_DEFAULT = std::make_shared<Shader>(
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec2 aTex;\n"
			"out vec2 TexCoord;\n"
			"uniform mat4x4 proj;\n"
			"uniform mat4x4 view;\n"
			"uniform mat4x4 model;\n"
			"uniform mat4x4 anchor;\n"
			"void main() {\n"
			"gl_Position = proj * view * model * anchor * vec4(vec3(aPos), 1.0);\n"
			"TexCoord = aTex;\n"
			"}\n",

			"#version 330 core\n"
			"in vec2 TexCoord;\n"
			"out vec4 FragColor;\n"
			"uniform sampler2D Tex;\n"
			"void main() {\n"
			"    FragColor = texture(Tex, TexCoord);\n"
			"}\n"
		);
	}

	void Renderer::renderScene(std::vector<Node>& sequence, Camera& camera) {
		glClear(GL_COLOR_BUFFER_BIT);

		// Note: Ensure the center point to be (0,0) for view trans to work properly!
		glm::mat4 proj = glm::ortho(-400.f, 400.f, -300.f, 300.f);
		glm::mat4 view = glm::inverse(camera.model_trans);

		// If contains Renderable component, render
		for (auto& node : sequence) {
			if (node->renderable) {
				node->renderable->render(proj, view, node->model_trans);
			}
		}
	}

}