#pragma once
#include <string>
#include <vector>

class Player
{
	string name_;
	string surname_;
	vector<string> skills_;
	short int height_;
public:
	Player(string name, string surname, short int height, vector<string> skills);
	Player(string name, string surname, short int height, int seed);
	Player(const Player &source);
	~Player();
	string getName();
	string getSurname();
	string getSkills();
	short int getHeight();
	string getDescription();
	Player rerollSkills(int seed);
};

