#pragma once
#include "Pokemon.h"
class Chimchar :
	public Pokemon
{
public:
	Chimchar();
	Chimchar(string inName);

	string showName();

	void quickAttack(Pokemon& opp);
	void flameWheel(Pokemon& opp);
	void detect();
	void ember(Pokemon& opp);
	void moveset(Pokemon& opp);
	void rivalmoveset(Pokemon& opp, int rivalmove);
};

