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

		viewport_w = width;
		viewport_h = height;

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
				glm::vec3(-this->anchor[0] * viewport_w, -this->anchor[1] * viewport_h, 0.f));

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

	void Sprite::setViewport(std::span<GLfloat> uv_coords) {
		double w = viewport_w = (uv_coords[2] - uv_coords[0]) * width;
		assert(w == viewport_w);
		double h = viewport_h = (uv_coords[5] - uv_coords[3]) * height;

		GLfloat vtx_coords[] = {
			0.0f, 0.0f, 0.0f,
			w, 0.0f, 0.0f,
			w, h, 0.0f,
			0.0f, h, 0.0f,
		};
		mesh->modData(vtx_coords, 0);
		mesh->modData(uv_coords, 12);
	}

}
