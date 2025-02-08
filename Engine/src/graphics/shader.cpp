#include "shader.h"

#include <stdexcept>

namespace engine {

	GLuint Shader::compileShader(const char* source, GLenum type) {
		GLuint shader = glCreateShader(type);
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);

		GLint success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			GLchar infoLog[512];
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			throw std::runtime_error(infoLog);
		}
		return shader;
	}

	Shader::Shader(const char* vertexShader, const char* fragmentShader) {
		GLuint vertex = compileShader(vertexShader, GL_VERTEX_SHADER);
		GLuint fragment = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

		program = glCreateProgram();
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glLinkProgram(program);
		glDeleteShader(vertex);
		glDeleteShader(fragment);

		GLint success;
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			GLchar infoLog[512];
			glGetProgramInfoLog(program, 512, nullptr, infoLog);
			throw std::runtime_error(infoLog);
		}
	}

	Shader::~Shader() {
		glDeleteProgram(program);
	}

}