#include "Includes.h"
using namespace std;

int main()
{
	srand(time(0));// this is used for later when deciding what opppponents randomly chosen move is

	string inpName;
	cout << "Hello! Welcome to the world of Pokemon!" << endl;
	cout << "Before we begin let's get to know eachother!" << endl;
	cout << "My name is Professor Magnolia. What's your name?" << endl;
	cin >> inpName; //store user input to variable inpName
	Trainer player = Trainer(inpName);// name your trainer user inputted name
	cout << "Hello " << player.showName() << "!" << endl;

	cout << "In this world, you will be able to get Pokemon" << endl;
	cout << "raise them and pit them in battle against each other!" << endl;

	int choice;
	cout << "I think its time you had your first pokemon!" << endl;
	cout << endl << "1 - Treeko" << endl;
	cout << "2 - Froakie" << endl;
	cout << "3 - Chimchar" << endl;
	cin >> choice;
	list <Pokemon> teamList;
	list <Pokemon> rivalTeam;
	Pokemon* starter;
	//depending on what numb user input decides what starter they get
	if (choice == 1)
	{
		string inName;
		int nickname; 
		cout << "Would you like to name your Treeko?" << endl;
		cout << endl << "1 - yes" << endl;
		cout << "2 - no" << endl;

		cin >> nickname;
		if (nickname == 1) //chooses treeko
		{
			cout << endl << "enter their name: ";
			cin >> inName;
			starter = new Treeko(inName); //gives user input nickname for pokemon
		}
		else
			starter = new Treeko();
	}
	else if (choice == 2)//chooses froakie
	{
		string inName;
		int nickname;
		cout << "Would you like to name your Froakie?" << endl;
		cout << endl << "1 - yes" << endl;
		cout << "2 - no" << endl;

		cin >> nickname;
		if (nickname == 1)
		{
			cout << endl << "enter their name: ";
			cin >> inName;
			starter = new Froakie(inName);
		}
		else
			starter = new Froakie();
	}
	else //chooses chimchar
	{
		string inName;
		int nickname;
		cout << "Would you like to name your Chimchar?" << endl;
		cout << endl << "1 - yes" << endl;
		cout << "2 - no" << endl;

		cin >> nickname;
		if (nickname == 1)
		{
			cout << endl << "enter their name: ";
			cin >> inName;
			starter = new Chimchar(inName); 
		}
		else
			starter = new Chimchar();
	}
	Pokemon team[3] = { *starter }; //list of starter pokemon
	teamList.push_back(*starter); //adds user chosen Pokemon to front of list
	Pokemon* rivStarter;
	cout << endl << "Congratulations you now have " << starter->showName() << "!" << endl;

	if (starter->type == "fire") // if user chooses chimchar, opponent uses Froakie
	{
		rivStarter = new Froakie();
	}
	else if (starter->type == "water")// if user chooses Froakie, opponent uses treeko
	{
		rivStarter = new Treeko();
	}
	else // if user chooses treeko, opponent uses chimchar
		rivStarter = new Chimchar();

	rivalTeam.push_back(*rivStarter); // adds opponents chosen pokemon to front of rival list

	cout << "This is your rival Conella" << endl;
	cout << "You will be battling against him and his Pokemon!" << endl;

	cout << "Lets get into your first battle!" << endl;
	cout << "You have entered battle with Conella!" << endl;
	cout << "He has sent out " << rivalTeam.begin()->showName() << endl;
	bool teamAlive = true;
	bool enemyAlive = true;
	int user_move; //input of user 
	int opp_move;
	while (teamAlive) //you only have the option to attack or go to your bag when your team is alive
	{
		int choice;
		cout << "What would you like to do?" << endl;
		cout << "1 - Attack" << endl;
		cout << "2 - Bag" << endl;
		cin >> user_move;
		if (user_move == 1) // show moveset and let user pick, also makes opponent moves after user chooses
		{
			starter->moveset(*rivalTeam.begin());
		}
		opp_move = (rand() % 4) + 1; // opponent moves randomly
		rivStarter->rivalmoveset(*teamList.begin(), opp_move);
		cout << "you have : " << teamList.begin()->showHealth() << " health!" << endl;
		cout << "they have : " << rivalTeam.begin()->showHealth() << " health!" << endl;
		int counter = 0;
		list<Pokemon> ::iterator it;
		for (it = teamList.begin(); it != teamList.end(); ++it)
		{
			if (it->health > 0)
			{
				counter++;
			}
			else
				counter = 0;
		}
		if (counter == 0)
			teamAlive = false; //you lost and now the game will end
		for (it = rivalTeam.begin(); it != rivalTeam.end(); ++it)
		{
			if (it->health > 0)
			{
				counter++;
			}
			else
				counter = 0;
		}
		if (counter == 0)
			enemyAlive = false; //you beat your opponent and will evolve depending on the type of the pokemon you chose from the beginning
		if (teamAlive && enemyAlive == false)
		{
			starter->health = 20;
			starter->levelUp(); //evolve
			cout << "Lets go again now that I've trained!" << endl;
			Pokemon* rivalUp;
			if (rivStarter->type == "fire") // if user chose chimchar, evolve to infernape
				rivalUp = new Infernape();
			else if (rivStarter->type == "water") // if user chose froakie, evolve to greninja
				rivalUp = new Greninja();
			else
				rivalUp = new Sceptile(); // if user chose treeko, evolve to sceptile
			rivalTeam.push_front(*rivalUp);
			rivalTeam.pop_back();
			cout << "You have entered battle with Conella!" << endl;
			cout << "He has sent out " << rivalTeam.begin()->showName() << endl;
			while (teamAlive || enemyAlive) // stay in loop while user pokemon or enemy pokemon is alive
			{
				int choice;
				cout << "What would you like to do?" << endl;
				cout << "1 - Attack" << endl;
				cout << "2 - Bag" << endl;
				cin >> user_move;
				if (user_move == 1)
				{
					starter->moveset(*rivalTeam.begin());
				}
				opp_move = (rand() % 4) + 1;
				rivalUp->rivalmoveset(*teamList.begin(), opp_move);
				cout << "you have : " << teamList.begin()->showHealth() << " health!" << endl;
				cout << "they have : " << rivalTeam.begin()->showHealth() << " health!" << endl;
				int counter = 0;
				list<Pokemon> ::iterator it;
				for (it = teamList.begin(); it != teamList.end(); ++it)
				{
					if (it->health > 0)
					{
						counter++;
					}
					else
						counter = 0;
				}
				if (counter == 0)
					teamAlive = false;
				for (it = rivalTeam.begin(); it != rivalTeam.end(); ++it)
				{
					if (it->health > 0)
					{
						counter++;
					}
					else
						counter = 0;
				}
				if (counter == 0)
					enemyAlive = false;
			}
		}

	}

	return 0;
}