#include "Sceptile.h"
#include "Includes.h"
Sceptile::Sceptile()
{
	level = 6;
	name = "Sceptile";
	type = "grass";
	speed = 9;
	abilityPower = 16;
	health = 33;
}
Sceptile::Sceptile(string inName) : Pokemon(inName)
{
	level = 6;
	type = "grass";
	speed = 9;
	abilityPower = 16;
	health = 33;
}

string Sceptile::showName()
{
	if (name == "Sceptile")
		return name;
	else
		return "Sceptile " + name;
}

void Sceptile::quickAttack(Pokemon& opp)
{
	speed = 100;
	opp.health -= 5;
	speed = 5;
}
void Sceptile::megaDrain(Pokemon& opp)
{
	if (opp.type != "water")
	{
		opp.health -= 2 + (abilityPower / 4);
		health += 2 + (abilityPower / 4);
	}
	else
	{
		opp.health -= 4 + (abilityPower / 4);
		health += 4 + (abilityPower / 4);
	}
}
void Sceptile::detect()
{
	health += 2;
}
void Sceptile::special(Pokemon& opp)
{
	opp.health -= 5;
}
void Sceptile::moveset(Pokemon& opp)
{
	int choice;
	cout << "What would you like to do" << endl;
	cout << "1 - Quick Attack" << endl;
	cout << "2 - Mega Drain" << endl;
	cout << "3 - Detect" << endl;
	cout << "4 - Special" << endl;
	cin >> choice;
	if (choice == 1)
	{
		this->quickAttack(opp);
	}
	else if (choice == 2)
	{
		this->megaDrain(opp);
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

void Sceptile::rivalmoveset(Pokemon& opp, int rivalmove)
{
	if (rivalmove == 1)
	{
		cout << "they used quick attack" << endl;
		this->quickAttack(opp);
	}
	else if (rivalmove == 2)
	{
		cout << "they used mega drain" << endl;
		this->megaDrain(opp);
	}
	else if (rivalmove == 3)
	{
		cout << "they used detect" << endl;
		this->detect();
	}
	else
	{
		cout << "they used special!" << endl;
		this->special(opp);
	}
}