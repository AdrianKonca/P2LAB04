#include "pch.h"
#include "Team.h"

Team::Team(const string name)
{
	this->name = name;
}

Team::Team(const Team &source)
{
	this->name = source.name;
	for (Player playerToAdd : source.players)
	{
		addPlayer(playerToAdd);
	}
}
void Team::addPlayer(Player playerToAdd)
{
	this->players.push_back(playerToAdd);
}

Player Team::getPlayer(int playerIndex)
{
	return players[playerIndex];
}

void Team::changePlayer(Player player, int playerIndex)
{
	this->players[playerIndex] = player;
}

string Team::getDescription()
{
	string description = "  Team's name: " + getName() + "\n";
	description += "   Player list:\n";
	for (Player player : players)
	{
		description += player.getDescription();
	}
	return description;
}

