#pragma once

#include "macros.h"

#include "renderable.h"

#include "glm/mat4x4.hpp"

#include <vector>
#include <memory>
#include <variant>
#include <iostream>



namespace engine
{

	/*
	SceneNode is responsible for building up the framework of the scene, providing
	the transformation matrices hierarchy. Various contents are attached to the
	framework, such as sprites, geometries, light, camera, etc, to provide actual
	rendering details.
	*/
	class ENGINE_API SceneNode
	{
		friend class Renderer;

	private:
		SceneNode* parent = nullptr; // no ownership
		std::vector<std::shared_ptr<SceneNode>> children;

		glm::mat4 model_trans_rel = glm::mat4(1.0f); // Relative to parent.
		glm::mat4 model_trans = glm::mat4(1.0f); // Absolute world transformation, for calculation.
		bool model_trans_dirty = true;

		// Object content.
		Renderable* renderable = nullptr; // no ownership

	public:
		SceneNode() = default;
		SceneNode(Renderable& renderable) : renderable(&renderable) {};
		SceneNode(const SceneNode& other) = default;
		SceneNode& operator=(const SceneNode& other) = default;
		SceneNode(SceneNode&& other) = default;
		SceneNode& operator=(SceneNode&& other) = default;

		std::shared_ptr<SceneNode> addChild();
		std::shared_ptr<SceneNode> addChild(Renderable& child);
		void updateModelTransRecursive(bool parent_trans_dirty = false);
		void translate(float trans_x, float trans_y);
		void rotate(float angle);
	};

	using Scene = SceneNode;
	using Camera = SceneNode;
	using Node = std::shared_ptr<SceneNode>;

}
