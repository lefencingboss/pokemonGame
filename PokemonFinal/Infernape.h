#pragma once
#include "Pokemon.h"
class Infernape :
	public Pokemon
{
public:
	Infernape();
	Infernape(string inName);

	string showName();
	void quickAttack(Pokemon& opp);
	void flameWheel(Pokemon& opp);
	void detect();
	void special(Pokemon& opp);
	void moveset(Pokemon& opp);
	void rivalmoveset(Pokemon& opp, int rivalmove);
};

