#include "sprite.h"

#include <iostream>
#include <string>
#include "stb_image.h"

namespace engine
{
	Sprite::Sprite(const char* fileName) : fileName(fileName) {
		image = stbi_load(fileName, &width, &height, &nchannels, 0);
		if (!image) {
			throw std::runtime_error("[Creating Sprite] Failed to load image: " + std::string(fileName));	
		}
	}

	Sprite::~Sprite() {
		if (image) { stbi_image_free(image); }
	}
}
