#pragma once
#include "Pokemon.h"
class Greninja :
	public Pokemon
{
public:
	Greninja();
	Greninja(string inName);

	string showName();

	void quickAttack(Pokemon& opp);
	void waterPulse(Pokemon& opp);
	void detect();
	void special(Pokemon& opp);
	void moveset(Pokemon& opp);
	void rivalmoveset(Pokemon& opp, int rivalmove);
};

