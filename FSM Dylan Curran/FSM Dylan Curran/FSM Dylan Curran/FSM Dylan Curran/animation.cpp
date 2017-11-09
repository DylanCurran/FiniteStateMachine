#include "animation.h"
#include "idle.h"
Animation::Animation()
{
	m_current = new Idle();
}
void Animation::idle() { m_current->idle(this); }
void Animation::jumping() { m_current->jumping(this); }
void Animation::hammering() { m_current->hammering(this); }
void Animation::shielding() { m_current->shielding(this); }
void Animation::firing() { m_current->firing(this); }