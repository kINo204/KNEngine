#include "render_command.h"

namespace engine {

	void RenderCommand::execute()
	{
		switch (type) {
		case Type::USE_SHADER:
			((Shader*)operand)->use();
			break;
		case Type::DRAW_ARRAYS:
		{
			MeshArray* m = (MeshArray*)operand;
			m->use();
			m->draw();
			MeshArray::disuse();
			break;
		}
		case Type::DRAW_ELEMENTS:
		{
			MeshElement* m = (MeshElement*)operand;
			m->use();
			m->draw();
			MeshElement::disuse();
			break;
		}
		case Type::CLEAR:
			break;
		case Type::SET_VIEWPORT:
			break;
		case Type::SET_CLEAR_COLOR:
			break;
		case Type::ENABLE_BLEND:
			break;
		case Type::DISABLE_BLEND:
			break;
		case Type::ENABLE_DEPTH_TEST:
			break;
		case Type::DISABLE_DEPTH_TEST:
			break;
		default:
			break;
		}
	}

}
