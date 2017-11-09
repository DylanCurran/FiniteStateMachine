#include "idle.h"

Idle::Idle()
{
}

Idle::~Idle()
{
}

void Idle::jumping(Animation * a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::hammering(Animation * a)
{
	std::cout << "Hammering" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::firing(Animation * a)
{
	std::cout << "Firing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::shielding(Animation * a)
{
	std::cout << "Shielding" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
