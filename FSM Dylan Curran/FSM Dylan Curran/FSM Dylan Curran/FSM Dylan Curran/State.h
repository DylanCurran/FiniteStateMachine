#ifndef STATE
#define STATE
#include <iostream>
#include "animation.h"



class State
{
public:
	virtual void idle(Animation* a) { std::cout << "State::Idling" << std::endl; }

	virtual void jumping(Animation* a) { std::cout << "State::Jumping" << std::endl; }

	virtual void hammering(Animation* a) { std::cout << "State::Hammering" << std::endl; }

	virtual void firing(Animation* a) { std::cout << "State::Swinging" << std::endl; }

	virtual void shielding(Animation* a) { std::cout << "State::Shielding" << std::endl; }

};
#endif // STATE