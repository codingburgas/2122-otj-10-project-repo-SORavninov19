#pragma once
#include <fstream>
#include <vector>
#include "../pm.types/User.h"
#include "../pm.types/Team.h"
#include "dataBaseAccess.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>


class DataTeams
{
	public:
	static std::vector<Team> teams;
	std::string fullCredential(int);
	void teamsDataBaseOpen();
	void teamDelete(int);
	void teamAdd(Team);
	void teamUpdate(Team, int);
};
