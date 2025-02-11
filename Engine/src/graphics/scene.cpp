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

	std::shared_ptr<SceneNode> SceneNode::addChild(Renderable& content) {
		std::shared_ptr<SceneNode> node = std::make_shared<SceneNode>(content);
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

	void SceneNode::updateModelTransRecursive(bool parent_trans_dirty) {
		bool dirty = false;
		if (parent != nullptr && (parent_trans_dirty || model_trans_dirty)) {
			model_trans = parent->model_trans * model_trans_rel;
			dirty = true;
			model_trans_dirty = false;
		}
		std::cout << model_trans_rel << std::endl;

		for (auto& child : children) {
			child->updateModelTransRecursive(dirty);
		}
	}

	void SceneNode::render(const glm::mat4& proj, const glm::mat4& view) {
		if (content) {
			content->render(proj, view, model_trans);
		}
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
