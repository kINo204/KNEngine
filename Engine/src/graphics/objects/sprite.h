#pragma once

#include "macros.h"
#include "../mesh.h"
#include "../shader.h"
#include "../renderable.h"
#include "../renderer.h"

#include "glm/vec2.hpp"
#include "glad/gl.h"

#include <stdexcept>
#include <memory>

namespace engine {

	class ENGINE_API Sprite : public Renderable
	{
	private:
		unsigned char* image = nullptr;
		std::unique_ptr<MeshElement> mesh = nullptr;
		std::shared_ptr<Shader> shader = Renderer::SHADER_SPRITE_DEFAULT;

		// Anchor point.
		glm::vec2 anchor = { 0.5f, 0.5f };

	public:
		Sprite() = default;
		Sprite(const char* fileName);
		~Sprite();

		void render(const glm::mat4&) override;
	};

}
