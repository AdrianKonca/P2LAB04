#pragma once
#include "Player.h"
#include <string>
#include <vector>

class Team
{
	string name;
	vector <Player> players;
public:
	Team(const string name);
	Team(const Team &source);

	string getName();
	string getDescription();
	Player getPlayer(int playerIndex);

	void addPlayer(Player playerToAdd);
	void changePlayer(Player player, int playerIndex);
};

