#include "shielding.h"

Shielding::Shielding()
{
}

Shielding::~Shielding()
{
}

void Shielding::idle(Animation * a)
{
	std::cout << "From idle to shielding" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
