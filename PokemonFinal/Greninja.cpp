#include "Greninja.h"
#include "Includes.h"
Greninja::Greninja()
{
	level = 6;
	name = "Greninja";
	type = "water";
	speed = 12;
	abilityPower = 16;
	health = 30;
}
Greninja::Greninja(string inName) : Pokemon(inName)
{
	level = 6;
	type = "water";
	speed = 12;
	abilityPower = 16;
	health = 30;
}

string Greninja::showName()
{
	if (name == "Greninja")
		return name;
	else
		return "Greninja " + name;
}

void Greninja::quickAttack(Pokemon& opp)
{
	speed = 100;
	opp.health -= 5;
	speed = 12;
}
void Greninja::waterPulse(Pokemon& opp)
{
	if (opp.type != "fire")
		health += 4 + (abilityPower / 4);
	else
		health += 6 + (abilityPower / 4);
}
void Greninja::detect()
{
	health += 2;
}
void Greninja::special(Pokemon& opp)
{
	opp.health -= 10;
}
void Greninja::moveset(Pokemon& opp)
{
	int choice;
	cout << "What would you like to do" << endl;
	cout << "1 - Quick Attack" << endl;
	cout << "2 - Water Pulse" << endl;
	cout << "3 - Detect" << endl;
	cout << "4 - Special" << endl;
	cin >> choice;
	if (choice == 1)
	{
		this->quickAttack(opp);
	}
	else if (choice == 2)
	{
		this->waterPulse(opp);
	}
	else if (choice == 3)
	{
		this->detect();
	}
	else
	{
		this->special(opp);
	}
}

void Greninja::rivalmoveset(Pokemon& opp, int rivalmove)
{
	if (rivalmove == 1)
	{
		cout << "they used quick attack" << endl;
		this->quickAttack(opp);
	}
	else if (rivalmove == 2)
	{
		cout << "they used water pulse" << endl;
		this->waterPulse(opp);
	}
	else if (rivalmove == 3)
	{
		cout << "they used detect" << endl;
		this->detect();
	}
	else
	{
		cout << "they used a special attack" << endl;
		this->special(opp);
	}
}
