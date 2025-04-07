#include "scene.h"

#include "glm/gtc/matrix_transform.hpp"

#include <iostream>

namespace engine {

	std::shared_ptr<SceneNode> SceneNode::addChild() {
		std::shared_ptr<SceneNode> node = std::make_shared<SceneNode>();
		node->parent = this;
		children.push_back(node);
		return node;
	}

	std::shared_ptr<SceneNode> SceneNode::addChild(Renderable& r) {
		std::shared_ptr<SceneNode> node = std::make_shared<SceneNode>(r);
		node->parent = this;
		children.push_back(node);
		return node;
	}

	std::ostream& operator<<(std::ostream & os, const glm::mat4 & node) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				os << node[i][j] << " ";
			}
			os << std::endl;
		}
		return os;
	}

	void SceneNode::updateCoordsRecursive(bool parent_trans_dirty) {
		bool dirty = false;
		if (parent != nullptr && (parent_trans_dirty || model_trans_dirty)) {
			model_trans = parent->model_trans * model_trans_rel;
			dirty = true;
			model_trans_dirty = false;
		}

		for (auto& child : children) {
			child->updateCoordsRecursive(dirty);
		}
	}

	std::vector<std::shared_ptr<SceneNode>> SceneNode::toSequence() {
		std::vector<std::shared_ptr<SceneNode>> sequence;

		// First-class children
		// Use value semantics; children are shared pointers
		for (auto node : children) sequence.push_back(node);

		// Add children recursively until done
		for (int i = 0; i < sequence.size(); i++) {
			for (auto& child : sequence[i]->children)
				sequence.push_back(child);
		}

		return sequence;
	}

	void SceneNode::translate(float trans_x, float trans_y) {
		glm::mat4 m = glm::translate(glm::mat4(1.f), glm::vec3(trans_x, trans_y, 0.f));
		model_trans_rel = m * model_trans_rel;
		model_trans_dirty = true;
	}

	/*
	Rotate around the anchor point.
	*/
	void SceneNode::rotate(float angle) {
		glm::mat4 m = glm::rotate(glm::mat4(1.f), glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));
		model_trans_rel = model_trans_rel * m;
		model_trans_dirty = true;
	}
}
