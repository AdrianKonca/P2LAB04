#pragma once
#include <vector>
#include <string>

class Skills
{
public:
	Skills();
	~Skills();
	static vector <string> skills_;
	static vector <string> generatSkills(int seed, unsigned int amount);
};

