#pragma once
#include <string>
using namespace std;
class Pokemon
{
public:
	string name;
	int level;
	int abilityPower;
	int speed;
	string type;
	int health;

public:
	Pokemon();
	Pokemon(string inName);

	virtual string showName();
	void levelUp();
	int showHealth();
	virtual void moveset(Pokemon& opp);
	virtual void rivalmoveset(Pokemon& opp, int rivalmove);
};

