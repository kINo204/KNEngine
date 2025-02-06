#pragma once

#include "macros.h"

#include "../renderable.h"
#include <stdexcept>
#include "glm/vec2.hpp"

namespace engine {

	class ENGINE_API Sprite : public Renderable
	{
	private:
		// Texture image.
		int width = 0, height = 0, nchannels = 0;
		unsigned char* image = nullptr;

		// Anchor point.
		glm::vec2 anchor = { 0.5f, 0.5f };

	public:
		Sprite() = default;
		Sprite(const char* fileName);
		~Sprite();
		void render() override;
	};

}
