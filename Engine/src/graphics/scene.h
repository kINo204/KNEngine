#pragma once

#include "macros.h"
#include <vector>
#include <memory>
#include "renderable.h"
#include "objects/sprite.h"
#include "glm/mat3x3.hpp"

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

		glm::mat3x3 worldTransRelative = glm::mat3x3(1.0f); // Relative to parent.
		glm::mat3x3 worldTrans = glm::mat3x3(1.0f); // Absolute world transformation, for calculation.
		bool worldTransDirty = true;

		// Object content.
		Renderable* content = nullptr; // no ownership

	public:
		SceneNode() = default;

		SceneNode(Renderable& content):
			content(&content)
		{}

		SceneNode(const SceneNode& other) = default;
		SceneNode& operator=(const SceneNode& other) = default;

		SceneNode(SceneNode&& other) = default;
		SceneNode& operator=(SceneNode&& other) = default;

		void addChild(const SceneNode& child);
	};

	using Scene = SceneNode;

}
