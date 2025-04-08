#include "animator.h"

#include "renderables/animation.h"

namespace engine
{

	void Animator::updateScene(std::vector<Node>& nodes, double time_delta) {
		for (auto& node : nodes) {
			if (node->renderable && node->renderable->type == Renderable::Type::ANIMATION) {
				Animation* anim = dynamic_cast<Animation*>(node->renderable);
				assert(anim != nullptr);
				anim->step(time_delta);
			}
		}
	}

}
