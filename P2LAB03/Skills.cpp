#include "pch.h"
#include "Skills.h"
vector <string> Skills::skills_ = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };


Skills::Skills()
{
}


Skills::~Skills()
{
}

vector <string> Skills::generatSkills(int seed, unsigned int amount)
{
	srand(seed);
	vector <string> skills;
	vector <bool> wasUsed(skills_.size());
	int randomIndex;
	while (skills.size() < amount)
	{
		randomIndex = rand() % skills_.size();
		if (wasUsed[randomIndex])
		{
			continue;
		}
		skills.insert(skills.begin(), skills_[randomIndex]);
		wasUsed[randomIndex] = true;
	}
	return skills;
}
