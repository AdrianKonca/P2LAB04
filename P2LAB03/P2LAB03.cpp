#include "pch.h"
#include "Skills.h"
#include "Player.h"
#include "Team.h"
#include <iostream>

int main()
{
	Team First = Team("Adamy");
	First.addPlayer(Player("Adam", "A", 170, 1));
	First.addPlayer(Player("Adam", "B", 171, 2));
	First.addPlayer(Player("Adam", "C", 172, 3));
	First.addPlayer(Player("Adam", "D", 173, 4));
	First.addPlayer(Player("Adam", "E", 174, 5));
	
	Team Second = Team("Damy");
	Second.addPlayer(Player("Damy", "A", 170, 6));
	Second.addPlayer(Player("Damy", "B", 171, 7));
	Second.addPlayer(Player("Damy", "C", 172, 8));
	Second.addPlayer(Player("Damy", "D", 173, 9));
	Second.addPlayer(Player("Damy", "E", 174, 10));
	Team Third = Team(Second);

	cout << First.getDescription();
	cout << Second.getDescription();
	cout << Third.getDescription();

	cout << endl << endl << endl;
	Third.changePlayer(Third.getPlayer(0).rerollSkills(3), 0);

	cout << First.getDescription();
	cout << Second.getDescription();
	cout << Third.getDescription();
}
