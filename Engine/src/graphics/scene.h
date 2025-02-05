#pragma once

#include "macros.h"
#include <vector>
#include <memory>
#include "objects/sprite.h"

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
	private:
		SceneNode* parent = nullptr; // no ownership
		std::vector<SceneNode> children;

		// Object content.
		Sprite* sprite = nullptr; // no ownership

	public:
		/* Generate an empty SceneNode. */
		SceneNode() = default;
		SceneNode(const SceneNode& other) = default;
		SceneNode& operator=(const SceneNode& other) = default;
		SceneNode(SceneNode&& other) = default;
		SceneNode& operator=(SceneNode&& other) = default;
		~SceneNode() = default;

		/* Generate a SceneNode with content. */
		template<typename T>
		SceneNode(T& content) : sprite(std::is_same_v<T, Sprite> ? (Sprite*)&content : nullptr) {}

		void addChild(const SceneNode& child);
	};

	using Scene = SceneNode;

}
