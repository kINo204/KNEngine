#pragma once

#include "glad/gl.h"

#include <array>
#include <span>

namespace engine {

	class MeshArray {
	private:
		GLuint vao, vbo;
		size_t count;

	public:
		MeshArray(
			const std::span<GLfloat> vertices,
			const std::span<std::array<size_t, 3>> attrib_config,
			size_t count);
		~MeshArray();

		void use();
		void draw();
		static void disuse();

	};

	class MeshElement {
	private:
		GLuint vao, vbo, ebo;
		size_t count;

	public:
		MeshElement(
			const std::span<GLfloat> vertices,
			const std::span<std::array<size_t, 3>> attrib_config,
			const std::span<GLuint> indices);
		~MeshElement();

		void modData(std::span<GLfloat> data, size_t ofs_count);
		void use();
		void draw();
		static void disuse();
	};

}
