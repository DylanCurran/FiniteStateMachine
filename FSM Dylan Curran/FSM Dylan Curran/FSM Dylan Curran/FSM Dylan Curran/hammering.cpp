#include "hammering.h"

Hammering::Hammering()
{
}

Hammering::~Hammering()
{
}

void Hammering::idle(Animation * a)
{
	std::cout << "From idle to hammering" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
