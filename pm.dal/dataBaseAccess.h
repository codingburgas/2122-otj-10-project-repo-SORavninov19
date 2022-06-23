#pragma once
#include <fstream>
#include <vector>
#include "../pm.types/User.h"

class DataBase
{
	std::vector<pm::types::User> users;
	public:

	std::string fullCredential(int);
	std::vector<pm::types::User> dataBaseOpen();
	void dataBaseDelete(int);
	void dataBaseAdd(pm::types::User);
	void dataBaseUpdate(pm::types::User, int);
};
