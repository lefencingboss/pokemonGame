#include "Treeko.h"
#include "Pokemon.h"
#include "Includes.h"
Treeko::Treeko() : Pokemon()
{
	level = 4;
	name = "Treeko";
	type = "grass";
	speed = 5;
	abilityPower = 10;
	health = 20;
}
Treeko::Treeko(string inName) : Pokemon(inName)
{
	level = 4;
	type = "grass";
	speed = 5;
	abilityPower = 10;
	health = 20;
}

string Treeko::showName()
{
	if (name == "Treeko")
		return name;
	else
		return "Treeko " + name;
}

void Treeko::quickAttack(Pokemon& opp)
{
	speed = 100;
	opp.health -= 5;
	speed = 5;
}
void Treeko::megaDrain(Pokemon& opp)
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
void Treeko::detect()
{
	health += 10;
}
void Treeko::leafage(Pokemon& opp)
{
	opp.health -= 5;
}
void Treeko::moveset(Pokemon& opp)
{
	int choice;
	cout << "What would you like to do" << endl;
	cout << "1 - Quick Attack" << endl;
	cout << "2 - Mega Drain" << endl;
	cout << "3 - Detect" << endl;
	cout << "4 - Leafage" << endl;
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
		this->leafage(opp);
	}
}

void Treeko::rivalmoveset(Pokemon& opp, int rivalmove)
{
	if (rivalmove == 1)
	{
		cout << "They used quick attack" << endl;
		this->quickAttack(opp);
	}
	else if (rivalmove == 2)
	{
		cout << "they used mega drain!" << endl;
		this->megaDrain(opp);
	}
	else if (rivalmove == 3)
	{
		cout << "they used detect" << endl;
		this->detect();
	}
	else
	{
		cout << "they used leafage" << endl;
		this->leafage(opp);
	}
}