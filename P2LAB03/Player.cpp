#include "pch.h"
#include "Player.h"
#include "Skills.h"

Player::Player(string name, string surname, short int height, vector<string> skills)
{
	name_ = name;
	surname_ = surname;
	skills_ = skills;
	height_ = height;
}

Player::Player(string name, string surname, short int height, int seed)
{
	name_ = name;
	surname_ = surname;
	skills_ = Skills::generatSkills(seed, 5);
	height_ = height;
}

Player::Player(const Player &source)
{
	name_ = source.name_;
	surname_ = source.surname_;
	skills_ = source.skills_;
	height_ = source.height_;
}

Player::~Player() {}

string Player::getName() {return name_;}
string Player::getSurname() {return surname_;}
short int Player::getHeight() {return height_;}

string Player::getSkills()
{
	string concatenatedSkills;
	for (string skill : skills_)
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
	return Player(name_, surname_, height_, seed);
}
