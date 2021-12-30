#pragma once
#include <string>

using namespace std;
class Trainer
{
protected:
	string name;

public:

	Trainer();
	Trainer(string inName);

	string showName();
};