#pragma once

#include "macros.h"

#include "glm/mat4x4.hpp"

namespace engine
{
	class ENGINE_API Renderable {
	public:
		const enum class Type {
			NONE,
			SPRITE,
			ANIMATION,
		} type;
		Renderable(Type t) : type(t) {}

		virtual void render(const glm::mat4&proj, const glm::mat4& view, const glm::mat4& model) = 0;
	};
}
