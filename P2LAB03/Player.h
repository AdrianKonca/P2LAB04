#pragma once
#include <string>
#include <vector>
#include <sstream>

class Player
{
	string name;
	string surname;
	vector<string> skills;
	short int height;
public:
	Player(string name, string surname, short int height, vector<string> skills);
	Player(string name, string surname, short int height, int seed);
	Player(string fileString);
	Player(const Player &source);
	~Player();

	string getName() { return name; };
	string getSurname() { return surname; };
	short int getHeight() { return height; };

	string getSkills();
	string getDescription();

	Player rerollSkills(int seed);
	string getSaveString();
	static vector<string> splitString(string line, string delimiter);
};

