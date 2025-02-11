#include "texture.h"

namespace engine {

	Texture::Texture(int tex_index, unsigned char data[], int width, int height, int nchannels) :
		index{tex_index}
	{
		glGenTextures(1, &txo);
		glActiveTexture(GL_TEXTURE0 + index);
		glBindTexture(GL_TEXTURE_2D, txo);

		GLuint channel = 0;
		if (nchannels == 1) { channel = GL_RED; }
		else if (nchannels == 3) { channel = GL_RGB; }
		else if (nchannels == 4) { channel = GL_RGBA; }

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, channel, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::use() {
        glBindTexture(GL_TEXTURE_2D, txo);
	}

    void Texture::disuse() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

	Texture::~Texture() {
		glDeleteTextures(1, &txo);
	}

}