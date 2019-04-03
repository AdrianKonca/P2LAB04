#include "pch.h"
#include "Player.h"
#include "Skills.h"

Player::Player(string name, string surname, short int height, vector<string> skills)
{
	this->name = name;
	this->surname = surname;
	this->skills = skills;
	this->height = height;
}

Player::Player(string name, string surname, short int height, int seed)
{
	this->name = name;
	this->surname = surname;
	this->skills = Skills::generatSkills(seed, 5);
	this->height = height;
}

Player::Player(const Player &source)
{
	this->name = source.name;
	this->surname = source.surname;
	this->skills = source.skills;
	this->height = source.height;
}

vector<string> Player::splitString(string line, string delimiter)
{
	vector<string> result;
	while (line.size()) {
		size_t index = line.find(delimiter);
		if (index != string::npos) {
			result.push_back(line.substr(0, index));
			line = line.substr(index + delimiter.size());
			if (line.size() == 0)result.push_back(line);
		}
		else {
			result.push_back(line);
			line = "";
		}
	}
	return result;
}


Player::Player(string line)
{
	const string delimiter = ",";
	vector<string> properties = splitString(line, delimiter);
	name = properties[0];
	surname = properties[1];
	height = stoi(properties[2]);
	skills = vector<string>();
	for (int i = 3; i < properties.size(); i++)
	{
		skills.push_back(properties[i]);
	}
}

Player::~Player() {}

string Player::getSkills()
{
	string concatenatedSkills;
	for (string skill : skills)
	{
		concatenatedSkills += skill + " ";
	}
	return concatenatedSkills;
}

string Player::getDescription()
{
	string description;
	description += "    Name of player: " + getName() + " " + getSurname() + "\n";
	description += "    Height: " + to_string(getHeight()) + "cm\n";
	description += "    Skills: " + getSkills() + "\n";
	return description;
}

Player Player::rerollSkills(int seed)
{
	this->skills = Skills::generatSkills(seed, 5);
	return *this;
}

string Player::getSaveString()
{
	const char DELIMITER = ',';
	stringstream save = stringstream();
	save << name << DELIMITER << surname << DELIMITER << height;
	for (string skill : skills)
	{
		save << DELIMITER << skill;
	}
	save << endl;
	return save.str();
}
