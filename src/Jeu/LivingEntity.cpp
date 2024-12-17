#include "pch.h"
#include "LivingEntity.h"

bool LivingEntity::isDead()
{
	if (mCurrentHealth <= 0)
	{
		return true;
	}

	return false;
}