#pragma once
#include "Pokemon.h"
class Froakie :
	public Pokemon
{
public:
	Froakie();
	Froakie(string inName);

	string showName();

	void quickAttack(Pokemon& opp);
	void waterPulse(Pokemon& opp);
	void detect();
	void bubble(Pokemon& opp);
	void moveset(Pokemon& opp);
	void rivalmoveset(Pokemon& opp, int rivalmove);
};