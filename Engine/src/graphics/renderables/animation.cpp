#include "animation.h"

namespace engine
{

	Animation::Animation(const char* fileName, int height_section, int height_interval, double time_frame) :
		Renderable(Type::ANIMATION),
		sprite(fileName),
		time_frame(time_frame),
		height_section(height_section), height_interval(height_interval)
	{
		GLfloat v_low, v_high;
		int H = sprite.height, h = height_section, d = height_interval, i = current_frame;
		v_high = 1 - i * (h + d) / H;
		v_low = v_high - h / H;
		GLfloat uv[] = {
			0, v_low,
			1, v_low,
			1, v_high,
			0, v_high,
		};
		sprite.setViewport(uv);
	}

	void Animation::render(const glm::mat4& proj, const glm::mat4& view, const glm::mat4& model) {
		sprite.render(proj, view, model);
		printf("Animation frame: %d\n", current_frame);
	}

	void Animation::stepAnimation(double delta_time) {
		if (!is_playing) return;

		timer += delta_time;
		while (timer > time_frame && current_frame < total_frame) {
			current_frame += 1;
			timer -= time_frame;
		}

		// If the animation is over:
		if (current_frame == total_frame) {
			if (!should_loop) {
				current_frame--; // "total_frame" is NOT a valid frame #!
				is_playing = false;
			} else {
				// Note: we didn't went back to the loop. This may cause the animation
				// to "freeze" during a long (slow) frame, and continue from that point
				// next frame.
				current_frame = 0;
			}
		}

		GLfloat v_low, v_high;
		GLfloat H = sprite.height, h = height_section, d = height_interval, i = current_frame;
		v_high = 1 - i * (h + d) / H;
		v_low = v_high - h / H;
		GLfloat uv[] = {
			0, v_low,
			1, v_low,
			1, v_high,
			0, v_high,
		};
		sprite.setViewport(uv);
	}

}