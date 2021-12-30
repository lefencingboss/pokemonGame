#include "Pokemon.h"
#include "Includes.h"
Pokemon::Pokemon()
{
	health = 20;
}
Pokemon::Pokemon(string inName)
{
	name = inName;
	health = 20;
}

string Pokemon::showName()
{
	return name;
}
int Pokemon::showHealth()
{
	return health;
}

void Pokemon::levelUp()
{
	cout << "Your pokemon leveled up!" << endl;
	level++;
	health += 5;
	speed += 3;
	abilityPower += 2;
}
void Pokemon::moveset(Pokemon& opp)
{

}
void Pokemon::rivalmoveset(Pokemon& opp, int rivalmove)
{

}