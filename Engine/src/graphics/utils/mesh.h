#pragma once

#include "glad/gl.h"

#include <array>
#include <span>

namespace engine {

	class Mesh {
	protected:
		GLuint vao = 0, vbo = 0;
		size_t count;
		Mesh(size_t count) : count{ count } {}

	public:
		void use() { glBindVertexArray(vao); }
		static void disuse() { glBindVertexArray(0); }
		void modData(std::span<GLfloat> data, size_t ofs_count);

		virtual void draw() = 0;
	};

	class MeshArray : public Mesh {
	public:
		MeshArray(
			const std::span<GLfloat> vertices,
			const std::span<std::array<size_t, 3>> attrib_config,
			size_t count);
		~MeshArray();

		void draw() override;
	};

	class MeshElement : public Mesh {
	private:
		GLuint ebo;

	public:
		MeshElement(
			const std::span<GLfloat> vertices,
			const std::span<std::array<size_t, 3>> attrib_config,
			const std::span<GLuint> indices);
		~MeshElement();

		void draw() override;
	};

}
