#pragma once
#include "Pokemon.h"
class Sceptile :
	public Pokemon
{
public:
	Sceptile();
	Sceptile(string inName);

	string showName();

	void quickAttack(Pokemon& opp);
	void megaDrain(Pokemon& opp);
	void detect();
	void special(Pokemon& opp);
	void moveset(Pokemon& opp);
	void rivalmoveset(Pokemon& opp, int rivalmove);
};

