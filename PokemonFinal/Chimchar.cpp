#include "Chimchar.h"
#include "Pokemon.h"
#include "Includes.h"

Chimchar::Chimchar()
{
	level = 4;
	name = "Chimchar";
	type = "fire";
	speed = 5;
	abilityPower = 10;
	health = 20;
}
Chimchar::Chimchar(string inName) : Pokemon(inName)
{
	level = 4;
	type = "fire";
	speed = 5;
	abilityPower = 10;
	health = 20;
}

string Chimchar::showName()
{
	if (name == "Chimchar")
		return name;
	else
		return "Chimchar " + name;
}

void Chimchar::quickAttack(Pokemon& opp)
{
	speed = 100;
	opp.health -= 5;
	speed = 5;
}
void Chimchar::flameWheel(Pokemon& opp)
{
	if (opp.type != "grass")
		opp.health -= 4 + (abilityPower / 4);
	else
		opp.health -= 6 + (abilityPower / 4);
}
void Chimchar::detect()
{
	health += 2;
}
void Chimchar::ember(Pokemon& opp)
{
	opp.health -= 5;
}
void Chimchar::moveset(Pokemon& opp)
{
	int choice;
	cout << "What would you like to do" << endl;
	cout << "1 - Quick Attack" << endl;
	cout << "2 - Flame Wheel" << endl;
	cout << "3 - Detect" << endl;
	cout << "4 - Ember" << endl;
	cin >> choice;
	if (choice == 1)
	{
		this->quickAttack(opp);
	}
	else if (choice == 2)
	{
		this->flameWheel(opp);
	}
	else if (choice == 3)
	{
		this->detect();
	}
	else
	{
		this->ember(opp);
	}
}

void Chimchar::rivalmoveset(Pokemon& opp, int rivalmove)
{
	if (rivalmove == 1)
	{
		cout << "They used quick attack" << endl;
		this->quickAttack(opp);
	}
	else if (rivalmove == 2)
	{
		cout << "They used flame wheel" << endl;
		this->flameWheel(opp);
	}
	else if (rivalmove == 3)
	{
		cout << "They used detect" << endl;
		this->detect();
	}
	else
	{
		cout << "They used ember" << endl;
		this->ember(opp);
	}
}