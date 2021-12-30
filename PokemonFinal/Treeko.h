#pragma once
#include "Pokemon.h"
#include "Trainer.h"
class Treeko :
	public Pokemon
{
public:
	Treeko();
	Treeko(string inName);

	string showName();

	void quickAttack(Pokemon& opp);
	void megaDrain(Pokemon& opp);
	void detect();
	void leafage(Pokemon& opp);
	void moveset(Pokemon& opp);
	void rivalmoveset(Pokemon& opp, int rivalmove);
};

