#pragma once

#include "macros.h"

#include "renderable.h"
#include "../utils/mesh.h"
#include "../utils/shader.h"
#include "../utils/texture.h"

#include "glm/vec2.hpp"
#include "glad/gl.h"

#include <memory>

namespace engine {

	class ENGINE_API Sprite : public Renderable
	{
	private:
		int width = 0, height = 0, nchannels = 0;
		std::unique_ptr<MeshElement> mesh = nullptr;
		std::unique_ptr<Texture> texture = nullptr;
		std::shared_ptr<Shader> shader = Shader::SHADER_DEFAULT;

		// Anchor point.
		glm::vec2 anchor = { 0.5f, 0.5f };

	public:
		Sprite(const char* fileName);

		void render(const glm::mat4& proj, const glm::mat4& view, const glm::mat4& model) override;
		void setAnchor(float x, float y) { anchor = { x, y }; }
	};

}
