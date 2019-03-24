#pragma once
#include "Player.h"
#include <string>
#include <vector>

class Team
{
private:
	string name_;
	vector <Player> players_;
public:
	Team(const string name);
	Team(const Team &source);
	string getName();
	void addPlayer(Player playerToAdd);
	string getDescription();
	Player getPlayer(int playerIndex);
};

