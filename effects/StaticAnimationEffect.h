//Author: MG

#ifndef SRC_EFFECTS_STATICANIMATIONEFFECT_H_
#define SRC_EFFECTS_STATICANIMATIONEFFECT_H_

#include "Effect.h"
#include "Animation.h"

class StaticAnimationEffect: public Effect {
protected:

	Animation mAnimation;
	double mStartTime;
	double mLifespan;
	bool mIsDead;

public:
	StaticAnimationEffect(Vector2f position, double lifeSpan, AnimationTemplate& animation, float _angle = 0, float _scale = 1);
	virtual ~StaticAnimationEffect();

	virtual void update();
	virtual void render();

	virtual bool isDead();
};

#endif /* SRC_EFFECTS_STATICANIMATIONEFFECT_H_ */
