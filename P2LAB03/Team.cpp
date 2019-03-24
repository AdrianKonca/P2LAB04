#include "pch.h"
#include "Team.h"
string Team::getName() { return name_; };

Team::Team(const string name)
{
	name_ = name;
}

Team::Team(const Team &source)
{
	name_ = source.name_;
	for (Player playerToAdd : source.players_)
	{
		addPlayer(playerToAdd);
	}
}
void Team::addPlayer(Player playerToAdd)
{
	players_.insert(players_.end(), playerToAdd);
}


Player Team::getPlayer(int playerIndex)
{
	return players_[playerIndex];
}

string Team::getDescription()
{
	string description = "  Team's name: " + getName() + "\n";
	description += "   Player list:\n";
	for (Player player : players_)
	{
		description += player.getDescription();
	}
	return description;
}