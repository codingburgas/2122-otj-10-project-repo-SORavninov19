#include "dataBaseAccess.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::vector<pm::types::User> DataBase::users;

std::string DataBase::fullCredential(int i)
{
	std::string a = " " ;
	return std::to_string(users[i].id) + a 
		+ users[i].level + a 
		+ users[i].username + a 
		+ users[i].firstName + a 
		+ users[i].lastName + a 
		+ users[i].dateOfCreation + a
		+ users[i].passwordHash + a
		+ users[i].dateOfLastChange + a
		+ std::to_string(users[i].idOfLastEditor) + a
		+ std::to_string(users[i].deleted);
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
				switch (i%11)
				{
				case 0:
					oneUser.id = stoi(word);
					break;
				case 1:
					oneUser.level = word;
					break;
				case 2:
					oneUser.username = word;
					break;
				case 3:
					oneUser.firstName = word;
					break;
				case 4:
					oneUser.lastName = word;
					break;
				case 5:
					oneUser.dateOfCreation = word;
					break;
				case 6:
					oneUser.passwordHash = word;
					break;
				case 7:
					oneUser.idOfCreator = stoi(word);
					break;
				case 8:
					oneUser.dateOfLastChange = word;
					break;
				case 9:
					oneUser.idOfLastEditor = std::stoi(word);
					break;
				case 10:
					oneUser.deleted = std::stoi(word);
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
	if (file.is_open()&& newFile.is_open())
	{
		std::string line;
		for (int i = 1; getline(file, line); i++)
		{
			if (i == id)
			{
				users.at(id - 1).deleted = true;
				newFile << line.substr(0,line.size()-1) << 1 << '\n';
			}
			else
			{
				std::string a = "|";
				newFile << line;
				newFile << '\n';
			}
		}
		newFile.close();
		file.close();
		remove("../database/users.txt");
		int a = rename("../database/newUsers.txt", "../database/users.txt");
	}
}

void DataBase::dataBaseAdd(pm::types::User nUser)
{
	std::ofstream file("../database/users.txt",std::ios::app);
	if (file.is_open())
	{
		file << nUser.id << '|'
			<< nUser.level << '|'
			<< nUser.username << '|'
			<< nUser.firstName << '|'
			<< nUser.lastName << '|'
			<< nUser.dateOfCreation << '|'
			<< nUser.passwordHash << '|'
			<< nUser.idOfCreator << '|'
			<< nUser.dateOfLastChange << '|'
			<< nUser.idOfLastEditor << '|'
			<< 0 << "\n";
		users.push_back(nUser);
		file.close();
	}
}

void DataBase::dataBaseUpdate(pm::types::User updateLine, int id)
{
	std::fstream file("../database/users.txt");
	std::ofstream newFile("../database/newUsers.txt");
	if (file.is_open() && newFile.is_open())
	{
		std::string line;
		for (int i = 1; getline(file, line); i++)
		{
			if (i == id)
			{
				users.at(id - 1) = updateLine;
				newFile << std::to_string(updateLine.id) << '|'
					<< updateLine.level << '|'
					<< updateLine.username << '|'
					<< updateLine.firstName << '|'
					<< updateLine.lastName << '|'
					<< updateLine.dateOfCreation << '|'
					<< updateLine.passwordHash << '|'
					<< std::to_string(updateLine.idOfCreator) << '|'
					<< updateLine.dateOfLastChange << '|'
					<< std::to_string(updateLine.idOfLastEditor) << '|'
					<< '0'
					<< std::endl;
			}
			else
			{
				std::string a = "|";
				newFile << line;
				newFile << '\n';
			}
		}
		newFile.close();
		file.close();
		remove("../database/users.txt");
		int a = rename("../database/newUsers.txt", "../database/users.txt");
	}
}

