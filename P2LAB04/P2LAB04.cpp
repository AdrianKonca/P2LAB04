#include "pch.h"
#include "Skills.h"
#include "Player.h"
#include "Team.h"
#include <iostream>

int main()
{
	Team First("Adamy");
	First.addPlayer(Player("Adam1", "A", 170, 1));
	First.addPlayer(Player("Adam2", "B", 171, 2));
	First.addPlayer(Player("Adam3", "C", 172, 3));
	First.addPlayer(Player("Adam4", "D", 173, 4));
	First.addPlayer(Player("Adam5", "E", 174, 5));
	
	Team Second("Piotry");
	Second.addPlayer(Player("Piotr1", "A", 170, 6));
	Second.addPlayer(Player("Piotr2", "B", 171, 7));
	Second.addPlayer(Player("Piotr3", "C", 172, 8));
	Second.addPlayer(Player("Piotr4", "D", 173, 9));
	Second.addPlayer(Player("Piotr5", "E", 174, 10));

	Team Third(Second);
	string filePath;
	cout << "Please enter a file name to load the team from (e.g. ""FourthTeam.txt""):";
	cin >> filePath;
	fstream file = Team::openFile(filePath);
	if (!file)
	{
		cout << "There is no such file as """ << filePath << """!" << endl << endl;
		return 0;
	}
	Team Fourth(file);
	cout << First.getDescription();
	cout << Second.getDescription();
	cout << Third.getDescription();
	cout << Fourth.getDescription();

	cout << endl << endl << endl;
	Third[0] = Third[0].rerollSkills(3);
	Fourth[0] = Fourth[0].rerollSkills(3);

	cout << First.getDescription();
	cout << Second.getDescription();
	cout << Third.getDescription();
	cout << Fourth.getDescription();

	First.save();
	Second.save();
	Third.save();
	Fourth.save();
}
