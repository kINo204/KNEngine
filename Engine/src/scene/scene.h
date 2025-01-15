#pragma once

#include <vector>

namespace engine
{

	/*
	The structure for a game scene.
	Consisting of arrays of components. We're not using a scene graph here for
	property of 2D games: components are most likely independent of each other,
	and arrays could avoid incontinuity of cache memory, boosting rendering
	performance.
	*/
	class Scene
	{
		//std::vector<T> actors;
	};

}

