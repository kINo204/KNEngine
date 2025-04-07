#pragma once

#include "macros.h"

#include "sprite.h"

namespace engine
{

	class ENGINE_API Animation : public Renderable {
	private:
		Sprite sprite;

		// Sprite picture info
		// Only support vertical sprite picture for now.
		int height_section, height_interval;

		// Animation status
		bool is_playing = false;
		int current_frame = 0, total_frame = 2;
		double timer = 0.0, const time_frame;

	public:
		// Configs
		bool should_loop = false;

		Animation(const char* fileName, int height_section, int height_interval, double time_frame = 0.1);

		void render(const glm::mat4& proj, const glm::mat4& view, const glm::mat4& model) override;
		void stepAnimation(double delta_time);

		void play() { is_playing = true; }
		void pause() { is_playing = false; }
		void reset() { is_playing = false; current_frame = 0; }
	};

}
