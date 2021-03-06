#pragma once
#include <fstream>
#include <vector>
#include "../pm.types/User.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

class DataBase
{
	public:
	static std::vector<pm::types::User> users;
	std::string fullCredential(int);
	void dataBaseOpen();
	void dataBaseDelete(int);
	void dataBaseAdd(pm::types::User);
	void dataBaseUpdate(pm::types::User, int);
};
