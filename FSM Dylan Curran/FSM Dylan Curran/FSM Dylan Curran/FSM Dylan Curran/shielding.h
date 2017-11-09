#ifndef SHIELDING
#define SHIELDING
#include "State.h"
#include "animation.h"
#include "idle.h"

class Shielding : public State
{
public:
	Shielding();
	~Shielding();
	void idle(Animation* a);
};

#endif // !SHIELDING

