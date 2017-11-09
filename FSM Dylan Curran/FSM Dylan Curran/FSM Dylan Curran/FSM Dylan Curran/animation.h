#ifndef ANIMATION
#define ANIMATION

#include <iostream>
class Animation
{
	class State* m_current;

public:
	Animation();

	void setCurrent(State* state) { m_current = state; }

	void idle();
	void jumping();
	void hammering();
	void shielding();
	void firing();


	

};
#endif	// ANIMATION
