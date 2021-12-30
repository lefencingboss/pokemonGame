#include "Froakie.h"
#include "Pokemon.h"
#include "Includes.h"
Froakie::Froakie()
{
	level = 4;
	name = "Froakie";
	type = "water";
	speed = 5;
	abilityPower = 10;
	health = 20;
}
Froakie::Froakie(string inName) : Pokemon(inName) 
{
	level = 4;
	type = "water";
	speed = 5;
	abilityPower = 10;
	health = 20;
}

string Froakie::showName()
{
	if (name == "Froakie")
		return name;
	else
		return "Froakie " + name; // this is for the user chooses to name their pokemon
}

void Froakie::quickAttack(Pokemon& opp)
{
	speed = 100;
	opp.health -= 5;
	speed = 5;
}
void Froakie::waterPulse(Pokemon& opp)
{
	if (opp.type != "fire") // if opponents type is fire
		opp.health += 4 + (abilityPower / 4);
	else
		opp.health += 6 + (abilityPower / 4);
}
void Froakie::detect()
{
	health += 2;
}
void Froakie::bubble(Pokemon& opp)
{
	opp.health -= 5;
}

//sets moves to user inputted numbers from 1-4 so that when inputted they will output a certain move
void Froakie::moveset(Pokemon& opp)
{
	int choice;
	cout << "What would you like to do" << endl;
	cout << "1 - Quick Attack" << endl;
	cout << "2 - Water Pulse" << endl;
	cout << "3 - Detect" << endl;
	cout << "4 - Bubble" << endl;
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
	else if (choice == 4)
	{
		this->bubble(opp);
	}
	else {
		cout << "Choose a valid option" << endl;
	}
}

//reads out what moves the opponent has made
void Froakie::rivalmoveset(Pokemon& opp, int rivalmove)
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
		cout << "they used bubble" << endl;
		this->bubble(opp);
	}
}