#pragma once

#include "macros.h"

#include "../scene_object.h"
#include <stdexcept>
#include "glm/vec2.hpp"
#include "glad/gl.h"

namespace engine {

	class ENGINE_API Sprite : public SceneObject
	{
	private:
		// Texture image.
		std::string fileName{};
		unsigned char* image = nullptr;
		int width = 0, height = 0, nchannels = 0;

		// Anchor point.
		glm::vec2 anchor = { 0.5f, 0.5f };

	public:
		Sprite() = default;
		Sprite(const char* fileName);
		~Sprite();
	};

}
