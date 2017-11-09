#ifndef HAMMERING
#define HAMMERING
#include "State.h"
#include "animation.h"
#include "idle.h"

class Hammering : public State
{
public:
	Hammering();
	~Hammering();
	void idle(Animation* a);
};

#endif // HAMMERING

