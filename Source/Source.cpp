#include <iostream>
#include "../pm.dal/dataBaseAccess.h"
#include "../pm.types/User.h"

int main()
{
	std::vector<pm::types::User> users;
	users = dataBaseOpen();
	std::cout << users[0].id << users[0].firstName << users[0].lastName<< users[0].email;
	}

