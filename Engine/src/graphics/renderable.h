#pragma once

#include "glm/mat4x4.hpp"

namespace engine
{
	class Renderable {
	public:
		virtual void render(const glm::mat4&proj, const glm::mat4& model) = 0;
	};
}
