#pragma once
#include "collidable.h"
#include "Attaque.h"

class LivingEntity : public collidable, public Attaque
{
public:

	int mMaxHealth;
	int mCurrentHealth;
	int mAttack;

};

