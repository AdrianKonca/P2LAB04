#pragma once
#include "Player.h"
#include <string>
#include <vector>

class Team
{
private:
	string name;
	vector <Player> players;
public:
	Team(const string name);
	Team(const Team &source);
	string getName();
	void addPlayer(Player playerToAdd);
	string getDescription();
	Player getPlayer(int playerIndex);
	void changePlayer(Player player, int playerIndex);
};

