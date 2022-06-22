#include "dataBaseAccess.h"
#include <fstream>
#include <string>
#include <sstream>

std::vector<pm::types::User> dataBaseOpen()
{
	std::vector<pm::types::User> users;
	std::fstream file("../database/users");
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			std::stringstream ssline(line);
			std::string word;
			pm::types::User oneUser;
			for (int i = 0; getline(ssline, word, '|'); i++)
			{
				switch (i%7)
				{		
				case 0:
					oneUser.id = stoi(word);
					break;
				case 1:
					oneUser.firstName = word;
					break;
				case 2:
					oneUser.lastName = word;
					break;
				case 3:
					oneUser.email = word;
					break;
				case 4:
					oneUser.age = stoi(word);
					break;
				case 5:
					oneUser.dateOfCreation = word;
					break;
				case 6:
					oneUser.passwordHash = word;
					break;
				}
			}
		}
	}
	else
		throw "database fail to open";
}
