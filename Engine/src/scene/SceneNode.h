#pragma once

namespace engine
{
#define ENGINE_SCENE_NODE_ENABLE_HIERACY 0;

	class SceneNode
	{

#if ENGINE_SCENE_NODE_ENABLE_HIERACY
		SceneNode* parent;
		std::vector<SceneNode*> children;
#endif

	};

}
