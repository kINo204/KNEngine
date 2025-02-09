#pragma once

#include "glad/gl.h"

#include <array>

namespace engine {

	class MeshArray {
	private:
		GLuint vao, vbo;
		int count;

	public:
		template <int LV, int LC>
		MeshArray(
			const std::array<GLfloat, LV>& vertices,
			const std::array<size_t, LC>& attrib_config)
		{
			glGenVertexArrays(1, &vao);
			glGenBuffers(1, &vbo);

			glBindVertexArray(vao);

			// Setup vertex buffer object.
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

			// Setup vertex attribute pointers.
			int stride = 0;
			for (int i = 0; i < attrib_config.size(); i++)
				stride += attrib_config[i];
			count = attrib_config.size() / stride;

			int pointer = 0;
			for (int i = 0; i < attrib_config.size(); i++) {
				glVertexAttrivPointer(i, attrib_config[i], GL_FLOAT, GL_FALSE,
					sizeof(GLfloat) * stride, (GLfloat*)(sizeof(GLfloat) * pointer));
				glEnableVertexAttribArray(i);
				pointer += attrib_config[i];
			}

			glBindVertexArray(0);
		}

		~MeshArray();

		void use();
		void draw();
		static void disuse();

	};

	class MeshElement {
	private:
		GLuint vao, vbo, ebo;
		int count;

	public:
		template<int LV, int LC, int LI> MeshElement(
			const std::array<GLfloat, LV>& vertices,
			const std::array<GLuint, LC>& attrib_config,
			const std::array<GLuint, LI>& indices)
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
			int stride = 0;
			for (size_t i = 0; i < attrib_config.size(); i++)
				stride += attrib_config[i];
			count = indices.size();

			int pointer = 0;
			for (size_t i = 0; i < attrib_config.size(); i++) {
				glVertexAttribPointer(i, attrib_config[i], GL_FLOAT, GL_FALSE,
					sizeof(GLfloat) * stride, (GLvoid*)(sizeof(GLfloat) * pointer));
				glEnableVertexAttribArray(i);
				pointer += attrib_config[i];
			}

			glBindVertexArray(0);
		}

		~MeshElement();

		void use();
		void draw();
		static void disuse();
	};

}
