#pragma once

#include "macros.h"

#include "glad/gl.h"
#include "glm/glm.hpp"

namespace engine {

	class ENGINE_API Shader
	{
	private:
		GLuint program;
		GLuint compileShader(const char* source, GLenum type);

	public:
		Shader(const char* vertexShader, const char* fragmentShader);
		~Shader();

		void use() const {
			glUseProgram(program); }

		void setBool(const char* name, bool value) const {
			glUniform1i(glGetUniformLocation(program, name), (int)value); }

		void setInt(const char* name, int value) const {
			glUniform1i(glGetUniformLocation(program, name), value); }

		void setFloat(const char* name, float value) const {
			glUniform1f(glGetUniformLocation(program, name), value); }

		void setVec2(const char* name, float x, float y) const {
			glUniform2f(glGetUniformLocation(program, name), x, y); }

		void setVec3(const char* name, float x, float y, float z) const {
			glUniform3f(glGetUniformLocation(program, name), x, y, z); }

		void setVec4(const char* name, float x, float y, float z, float w) const {
			glUniform4f(glGetUniformLocation(program, name), x, y, z, w); }

		void setMat4(const char* name, const glm::mat4x4& m) const {
			glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &m[0][0]); }
	};

}
