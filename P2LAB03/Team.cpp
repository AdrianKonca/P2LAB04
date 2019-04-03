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

Team::Team(fstream &dataFile)
{
	string line;
	dataFile >> line;
	name = line;
	while (!dataFile.eof())
	{
		dataFile >> line;
		addPlayer(Player(line));
	}
}

void Team::addPlayer(Player playerToAdd)
{
	this->players.push_back(playerToAdd);
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


string Team::createFileName()
{
	const string filePreName = "Team";
	const string fileExtenstion = ".txt";
	stringstream fileName = stringstream();
	time_t now = time(0);
	tm nowLocal;
	localtime_s(&nowLocal, &now);
	fileName << filePreName << name << (nowLocal.tm_hour) << (nowLocal.tm_min) << (nowLocal.tm_sec) << fileExtenstion;
	return fileName.str();
}


void Team::save()
{
	fstream saveFile;
	saveFile.open(createFileName(), fstream::out);
	stringstream saveStream = stringstream();
	saveStream << name << endl;
	for (Player player : players)
	{
		saveStream << player.getSaveString();
	}
	saveFile << saveStream.str();
	saveFile.flush();
	saveFile.close();
}

fstream Team::openFile(string filePath)
{
	fstream saveFile;
	saveFile.open(filePath, fstream::in);
	return saveFile;
}