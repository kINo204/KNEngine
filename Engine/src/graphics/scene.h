#pragma once

#include "macros.h"
#include "renderable.h"

#include "glm/mat4x4.hpp"

#include <vector>
#include <memory>
#include <variant>


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
		std::vector<SceneNode> children;

		glm::mat4 model_trans_rel_ = glm::mat4(1.0f); // Relative to parent.
		glm::mat4 model_trans_ = glm::mat4(1.0f); // Absolute world transformation, for calculation.
		bool model_trans_dirty_ = true;

		// Object content.
		Renderable* content = nullptr; // no ownership

	public:
		SceneNode() = default;
		SceneNode(Renderable& content) : content(&content) {};
		SceneNode(const SceneNode& other) = default;
		SceneNode& operator=(const SceneNode& other) = default;
		SceneNode(SceneNode&& other) = default;
		SceneNode& operator=(SceneNode&& other) = default;

		void addChild(Renderable& child);
		void updateModelTransRecursive(bool parent_trans_dirty = false);
	};

	using Scene = SceneNode;

}
