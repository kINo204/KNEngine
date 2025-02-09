#pragma once

#include "shader.h"
#include "mesh.h"

namespace engine {

	class RenderCommand {
	public:
		enum class Type {
			USE_SHADER,
			DRAW_ARRAYS,
			DRAW_ELEMENTS,
			CLEAR,
			SET_VIEWPORT,
			SET_CLEAR_COLOR,
			ENABLE_BLEND,
			DISABLE_BLEND,
			ENABLE_DEPTH_TEST,
			DISABLE_DEPTH_TEST,
		};

	private:
		Type type;
		void* operand = nullptr;

	public:
		RenderCommand(Type type, void* operand) : type(type), operand(operand) {};

		void execute();
	};

}
