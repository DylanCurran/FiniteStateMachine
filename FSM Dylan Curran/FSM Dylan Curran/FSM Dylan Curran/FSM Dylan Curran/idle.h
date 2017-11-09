#ifndef IDLE
#define IDLE
#include "State.h"
#include "animation.h"
class Idle: public State
{
public:
	Idle();
	~Idle();

	void jumping(Animation* a);
	void hammering(Animation* a);
	void firing(Animation* a);
	void shielding(Animation* a);

};

#endif // !IDLE

