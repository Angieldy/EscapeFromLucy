#include "pch.h"
#include "Attaque.h"

Attaque::Attaque()
{

}

int Attaque::attack(int att, int def)
{
	int pvLost;

	if (att <= def)
	{
		pvLost = def - att;
		return pvLost;
	}
	else
	{
		pvLost = att - def;
		return pvLost;
	}
}