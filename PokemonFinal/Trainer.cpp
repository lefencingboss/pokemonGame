#include "Trainer.h"
#include <iostream>
#include <string>

using namespace std;

Trainer::Trainer()
{
	name = "Red";
}

Trainer::Trainer(string inName)
{
	this->name = inName;
}

string Trainer::showName()
{
	return name;
}