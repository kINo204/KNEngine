#pragma once

#include "../core/scene.h"

namespace engine
{

	class Animator {
	public:
		void updateScene(std::vector<Node>& nodes, double time_delta);
	};

}
