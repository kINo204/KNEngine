#include "sprite.h"

#include "stb_image.h"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <string>


namespace engine
{

	Sprite::Sprite(const char* fileName)
	{
		// Load the texture image.
		unsigned char* image = stbi_load(fileName, &width, &height, &nchannels, 0);
		if (!image) {
			throw std::runtime_error("[Creating Sprite] Failed to load image: " + std::string(fileName));
		}
		texture = std::make_unique<Texture>(0, image, width, height);
		stbi_image_free(image);

		// Setup mesh object.
		mesh = std::make_unique<MeshElement>(
			std::array<GLfloat, 20>{	// positions				// texture coords
				0.0f, 0.0f, 0.0f,					0.0f, 0.0f,
				(float)width, 0.0f, 0.0f,			1.0f, 0.0f,
				(float)width, (float)height, 0.0f,	1.0f, 1.0f,
				0.0f, (float)height, 0.0f,			0.0f, 1.0f
			},
			std::array<GLuint, 2>{ 3, 2 }, // attribute config
			std::array<GLuint, 6>{ 0, 1, 2, 2, 3, 0 } // indices
		);
	}

    void Sprite::render(const glm::mat4& proj, const glm::mat4& view, const glm::mat4& model) {
		glm::mat4 anchor = glm::translate(glm::mat4(1.f),
			glm::vec3(-this->anchor[0] * width, -this->anchor[1] * height, 0.f));

		texture->use();

		shader->use();
		shader->setMat4("proj", proj);
		shader->setMat4("view", view);
		shader->setMat4("model", model);
		shader->setMat4("anchor", anchor);
		shader->setInt("Tex", 0); // 设置shader uniform变量以使用texture

		mesh->use();

		mesh->draw();

		mesh->disuse();
		texture->disuse();
	}

}
