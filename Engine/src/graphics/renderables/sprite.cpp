#include "sprite.h"

#include "stb_image.h"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <array>
#include <span>


namespace engine
{

	Sprite::Sprite(const char* fileName): Renderable(Type::SPRITE)
	{
		// Load the texture image.
		unsigned char* image = stbi_load(fileName, &width, &height, &nchannels, 0);
		if (!image) {
			throw std::runtime_error("[Creating Sprite] Failed to load image: " + std::string(fileName));
		}
		texture = std::make_unique<Texture>(0, image, width, height, nchannels);
		stbi_image_free(image);

		// Setup mesh object.
		GLfloat vertices[] = {
			// coords
			0.0f, 0.0f, 0.0f,
			width, 0.0f, 0.0f,
			width, height, 0.0f,
			0.0f, height, 0.0f,
			// uv coords
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
		};
		std::array<size_t, 3> attrib_cfg[] = {
			{0, 3, 3},
			{12, 2, 2}
		};
		GLuint indices[] = { 0, 1, 2, 2, 3, 0 };
		mesh = std::make_unique<MeshElement>(vertices, attrib_cfg, indices);
	}

    void Sprite::render(const glm::mat4& proj, const glm::mat4& view, const glm::mat4& model) {
		glm::mat4 anchor_trans = glm::translate(glm::mat4(1.f),
				glm::vec3(-this->anchor[0] * width, -this->anchor[1] * height, 0.f));

		texture->use();

		shader->use();
		shader->setMat4("proj", proj);
		shader->setMat4("view", view);
		shader->setMat4("model", model);
		shader->setMat4("anchor", anchor_trans);
		shader->setInt("Tex", 0);

		mesh->use();

		mesh->draw();

		mesh->disuse();
		texture->disuse();
	}

}
