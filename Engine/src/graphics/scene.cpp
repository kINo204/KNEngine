#include "scene.h"

namespace engine {

	void SceneNode::addChild(Renderable& child)
	{
		SceneNode node{child};
		node.parent = this;
		children.push_back(std::move(node));
	}

	void SceneNode::updateModelTransRecursive(bool parent_trans_dirty) {
		bool dirty = false;
		if (parent != nullptr && (parent_trans_dirty || model_trans_dirty_)) {
			model_trans_ = model_trans_rel_ * parent->model_trans_;
			dirty = true;
			model_trans_dirty_ = false;
		}
		for (auto& child : children) {
			child.updateModelTransRecursive(dirty);
		}
	}
}
