#pragma once

#include "glad/gl.h"

namespace engine {

	class Texture {
	private:
		GLuint txo;
		int index; // Starting from 0.

	public:
		Texture(int tex_index, unsigned char data[], int width, int height);
		~Texture();
		void use();
		void disuse();
	};
}
