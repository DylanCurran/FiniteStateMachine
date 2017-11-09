#ifndef JUMPING
#define JUMPING
#include "State.h"
#include "animation.h"
#include "idle.h"
class Jumping : public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation* a);
};

#endif // !JUMPING
