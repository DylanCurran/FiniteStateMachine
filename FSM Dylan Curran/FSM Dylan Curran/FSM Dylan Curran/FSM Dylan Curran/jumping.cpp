#include "jumping.h"

Jumping::Jumping()
{
}

Jumping::~Jumping()
{
}

void Jumping::idle(Animation * a)
{
	std::cout << "From idle to jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
