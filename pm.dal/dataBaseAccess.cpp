#include "dataBaseAccess.h"
#include <fstream>
#include <string>
#include <sstream>


std::string DataBase::fullCredential(int i)
{
	std::string a = " " ;
	return std::to_string(users[i].id) + a + users[i].firstName + a + users[i].lastName + a + users[i].email + a + std::to_string(users[i].age) + a + users[i].dateOfCreation + a + users[i].passwordHash;

}

void DataBase::dataBaseOpen()
{
	std::fstream file("../database/users.txt");

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
			users.push_back(oneUser);
		}
	}
}

void DataBase::dataBaseDelete(int id)
{
	std::fstream file("../database/users.txt");
	std::ofstream newFile("../database/newUsers.txt");
	if (file.is_open())
	{
		std::string line;
		for (int i = 0; getline(file, line); i++)
		{
			if (i == id)
			{
				users.erase(users.begin() + id);
			}
			else
			{
				std::string a = "|";
				newFile << line;
				newFile << '\n';
			}
		}
		
	}
}

