#include "scene.h"

namespace engine {

	void SceneNode::addChild(const SceneNode& child)
	{
		this->children.push_back(child);
	}
}
