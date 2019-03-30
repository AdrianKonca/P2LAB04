#pragma once
#include "Player.h"
#include <string>
#include <vector>
#include <fstream>

class Team
{
	string name;
	vector <Player> players;
public:
	Team(const string name);
	Team(const Team &source);

	Player operator [](int i) const { return players[i]; }
	Player & operator [](int i) { return players[i]; }

	string getName() { return name; };

	string getDescription();

	void addPlayer(Player playerToAdd);
	void changePlayer(Player player, int playerIndex);
	void save();
	string createFileName();
};

