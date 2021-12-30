#include "Infernape.h"
#include "Includes.h"
Infernape::Infernape()
{
	level = 6;
	name = "Infernape";
	type = "fire";
	speed = 10;
	abilityPower = 16;
	health = 30;
}
Infernape::Infernape(string inName) : Pokemon(inName)
{
	level = 6;
	type = "fire";
	speed = 10;
	abilityPower = 16;
	health = 30;
}

string Infernape::showName()
{
	if (name == "Infernape")
		return name;
	else
		return "Infernape " + name;
}

void Infernape::quickAttack(Pokemon& opp)
{
	speed = 100;
	opp.health -= 5;
	speed = 10;
}
void Infernape::flameWheel(Pokemon& opp)
{
	if (opp.type != "grass")
		health += 4 + (abilityPower / 4);
	else
		health += 6 + (abilityPower / 4);
}
void Infernape::detect()
{
	health += 2;
}
void Infernape::special(Pokemon& opp)
{
	opp.health -= 10;
}
void Infernape::moveset(Pokemon& opp)
{
	int choice;
	cout << "What would you like to do" << endl;
	cout << "1 - Quick Attack" << endl;
	cout << "2 - Flame Wheel" << endl;
	cout << "3 - Detect" << endl;
	cout << "4 - Special Move" << endl;
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
		this->special(opp);
	}
}
void Infernape::rivalmoveset(Pokemon& opp, int rivalmove)
{
	if (rivalmove == 1)
	{
		cout << "they used quick attack" << endl;
		this->quickAttack(opp);
	}
	else if (rivalmove == 2)
	{
		cout << "they used flame wheel " << endl;
		this->flameWheel(opp);
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