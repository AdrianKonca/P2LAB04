#pragma once
#include <vector>
#include <string>

class Skills
{
	static vector <string> skills_;
public:
	Skills();
	~Skills();
	static vector <string> generatSkills(int seed, unsigned int amount);
};

