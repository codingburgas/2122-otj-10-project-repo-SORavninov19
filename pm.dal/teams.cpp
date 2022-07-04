#include "teams.h"

std::vector<Team> DataTeams::teams;

std::string DataTeams::fullCredential(int i)
{
	std::string a = " ";
	std::string fullCredit = std::to_string(teams[i].id) + a
		+ teams[i].title + a
		+ teams[i].dateOfCreation + a
		+ teams[i].creator.username + a
		+ teams[i].dateOfLastChange + a
		+ DataBase::users[teams[i].idOfLastEditor - 1].username + a;
	fullCredit += '(';
	for (size_t j = 0; j < teams[i].assignedUsers.size() - 1; j++)
	{
		fullCredit = fullCredit + teams[i].assignedUsers[j].username + ',';
	}
	fullCredit = fullCredit + teams[i].assignedUsers[teams[i].assignedUsers.size() - 1].username;
	fullCredit += ') ';
	fullCredit += std::to_string(teams[i].deleted);
	return fullCredit;
}
void DataTeams::teamsDataBaseOpen()
{
	std::fstream file("../database/teams.txt");

	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			std::stringstream ssline(line);
			std::string word;
			Team oneTeam;
			for (int i = 0; getline(ssline, word, '|'); i++)
			{
				std::stringstream ssword(word);
				std::string id;
				switch (i % 9)
				{
				case 0:
					oneTeam.id = stoi(word);
					break;
				case 1:
					oneTeam.title = word;
					break;
				case 2:
					oneTeam.dateOfCreation = word;
					break;
				case 3:
					oneTeam.idOfCreator = stoi(word);
					break;
				case 4:
					oneTeam.dateOfLastChange = word;
					break;
				case 5:
					oneTeam.idOfLastEditor = stoi(word);
					break;
				case 6:
					oneTeam.creator = DataBase::users[stoi(word)];
					break;
				case 7:
					for (int j = 0; getline(ssword, id, ','); j++)
					{
						oneTeam.assignedUsers.push_back(DataBase::users[stoi(id)-1]);
					}
					break;
				case 8:
					oneTeam.deleted = std::stoi(word);
					break;
				}
			}
			teams.push_back(oneTeam);
		}
	}
}

void DataTeams::teamDelete(int id)
{
	std::fstream file("../database/teams.txt");
	std::ofstream newFile("../database/newTeams.txt");
	if (file.is_open() && newFile.is_open())
	{
		std::string line;
		for (int i = 1; getline(file, line); i++)
		{
			if (i == id)
			{
				//users.at(id - 1).deleted = true;
				newFile << line.substr(0, line.size() - 1) << 1 << '\n';
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
		remove("../database/teams.txt");
		int a = rename("../database/newTeams.txt", "../database/teams.txt");
	}
}

void DataTeams::teamAdd(Team nTeam)
{
	std::ofstream file("../database/teams.txt", std::ios::app);
	if (file.is_open())
	{
		file << nTeam.id << '|'
			<< nTeam.title << '|'
			<< nTeam.dateOfCreation << '|'
			<< nTeam.idOfCreator << '|'
			<< nTeam.dateOfLastChange << '|'
			<< nTeam.idOfLastEditor << '|'
			<< nTeam.creator.id << '|';
		for (int i = 0;i < nTeam.assignedUsers.size()-1; i++)
		{
			file << nTeam.assignedUsers[i].id << ',';
		}
		file << nTeam.assignedUsers[nTeam.assignedUsers.size() - 1].id;
		file << '|';
		file << 0 << "\n";
		DataTeams::teams.push_back(nTeam);
		file.close();
	}
}

void DataTeams::teamUpdate(Team updateLine, int id)
{
	std::fstream file("../database/teams.txt");
	std::ofstream newFile("../database/newTeams.txt");
	if (file.is_open() && newFile.is_open())
	{
		std::string line;
		for (int i = 1; getline(file, line); i++)
		{
			if (i == id)
			{
				newFile << updateLine.id << '|'
					<< updateLine.title << '|'
					<< updateLine.dateOfCreation << '|'
					<< updateLine.idOfCreator << '|'
					<< updateLine.dateOfLastChange << '|'
					<< updateLine.idOfLastEditor << '|'
					<< updateLine.creator.id << '|';
				for (int j = 0; j < updateLine.assignedUsers.size() - 1; j++)
				{
					newFile << updateLine.assignedUsers[j].id << ',';
				}
				newFile << updateLine.assignedUsers[updateLine.assignedUsers.size() - 1].id;
				newFile << '|';
				newFile << 0 << "\n";
			}
			else
			{
				newFile << line;
				newFile << '\n';
			}
		}
		newFile.close();
		file.close();
		remove("../database/teams.txt");
		int a = rename("../database/newTeams.txt", "../database/teams.txt");
	}
}

