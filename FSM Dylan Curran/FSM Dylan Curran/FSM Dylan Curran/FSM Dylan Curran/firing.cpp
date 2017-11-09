#include "firing.h"

Firing::Firing()
{
}

Firing::~Firing()
{
}

void Firing::idle(Animation * a)
{
	std::cout << "From Idle to Firing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
