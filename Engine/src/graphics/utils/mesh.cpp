#include "mesh.h"

namespace engine {

	MeshArray::MeshArray(
		const std::span<GLfloat> vertices,
		const std::span<std::array<size_t, 3>> attrib_config,
		size_t count) : count{ count }
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);

		// Setup vertex buffer object.
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

		// Setup vertex attribute pointers.
		for (size_t i = 0; i < attrib_config.size(); i++) {
			auto& [pointer, size, stride] = attrib_config[i];
			glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE,
				sizeof(GLfloat) * stride, (GLvoid*)(sizeof(GLfloat) * pointer));
			glEnableVertexAttribArray(i);
		}

		glBindVertexArray(0);
	}

	void MeshArray::use() {
		glBindVertexArray(vao);
	}

	void MeshArray::disuse() {
		glBindVertexArray(0);
	}

	void MeshArray::draw() {
		glDrawArrays(GL_TRIANGLES, 0, count);
	}

	MeshArray::~MeshArray() {
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
	}

	MeshElement::MeshElement(
		const std::span<GLfloat> vertices,
		const std::span<std::array<size_t, 3>> attrib_config,
		const std::span<GLuint> indices) : count{ indices.size() }
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);

		glBindVertexArray(vao);

		// Setup vertex buffer object.
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

		// Setup vertex attribute pointers.
		for (size_t i = 0; i < attrib_config.size(); i++) {
			auto& [pointer, size, stride] = attrib_config[i];
			glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE,
				sizeof(GLfloat) * stride, (GLvoid*)(sizeof(GLfloat) * pointer));
			glEnableVertexAttribArray(i);
		}

		glBindVertexArray(0);
	}

	void MeshElement::modData(std::span<GLfloat> data, size_t ofs_count) {
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferSubData(GL_ARRAY_BUFFER, ofs_count * sizeof(GLfloat), data.size() * sizeof(GLfloat), data.data());
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void MeshElement::use() {
		glBindVertexArray(vao);
	}

	void MeshElement::disuse() {
		glBindVertexArray(0);
	}

	void MeshElement::draw() {
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}

	MeshElement::~MeshElement() {
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);
	}

}
