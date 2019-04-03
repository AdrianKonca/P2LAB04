#pragma once
#include "Player.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>


class Team
{
	string name;
	vector <Player> players;
public:
	Team(const string name);
	Team(const Team &source);
	Team(fstream dataFile);

	Player operator [](int i) const { return players[i]; }
	Player & operator [](int i) { return players[i]; }

	string getName() { return name; };

	string getDescription();

	void addPlayer(Player playerToAdd);
	void changePlayer(Player player, int playerIndex);
	void save();
	string createFileName();
	static fstream openFile(string filePath);
};

