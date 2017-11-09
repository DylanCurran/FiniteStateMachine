#ifndef FIRING
#define FIRING
#include "State.h"
#include "animation.h"
#include "idle.h"


class Firing : public State
{
public:
	Firing();
	~Firing();
	void idle(Animation* a);

};

#endif // FIRING

