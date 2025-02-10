#include "scene.h"

#include "glm/gtc/matrix_transform.hpp"

namespace engine {

	SceneNode& SceneNode::addChild(Renderable& child)
	{
		children.push_back({child});
		SceneNode& node = *(children.end() - 1);
		node.parent = this;
		return node;
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

	void SceneNode::render(const glm::mat4& proj) {
		if (content) {
			content->render(proj, model_trans_);
		}
	}

	void SceneNode::translate(float trans_x, float trans_y) {
		glm::mat4 m = glm::translate(glm::mat4(1.f), glm::vec3(trans_x, trans_y, 0.f));
		model_trans_rel_ = m * model_trans_rel_;
		model_trans_dirty_ = true;
	}

	void SceneNode::rotate(float angle) {
		glm::mat4 m = glm::rotate(glm::mat4(1.f), glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));
		model_trans_rel_ = model_trans_rel_ * m;
		model_trans_dirty_ = true;
	}
}
