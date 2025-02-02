#pragma once

#include <vector>

#include "SceneNode.h"

namespace engine
{

	/* Consisting of arrays of components. We're not using a scene graph here for
	property of 2D games: components are most likely independent of each other,
	and arrays could avoid incontinuity of cache memory, boosting rendering
	performance.
	However, the SceneNode structure still supports adding children to a node,
	making it possible to create a local graph if needed. */

	/*
	The structure for a game scene.
	*/
	class Scene
	{
		std::vector<SceneNode> nodes;
	};

}

