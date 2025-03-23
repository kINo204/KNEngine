#include "mesh.h"

namespace engine {

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
