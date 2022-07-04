#include "menu.h"

using namespace std;

pm::types::User logedUser;
DataBase db;
DataTeams tdb;

void pressAnyKey()
{
	cout << "\nPress any key to continue";
	char a = _getch();
}

string toLowerCase(string text)
{
	std::for_each(text.begin(), text.end(), [](char& c) {
		c = ::tolower(c);
		});
	return text;
}

string findCurrentTime()
{
	time_t curtime;

	time(&curtime);

	return ctime(&curtime);
}

void createUser()
{
	string confirmPass = "";
	pm::types::User nUser;

	do
	{
		//solves potentional getline problems
		cin.ignore(100, '\n');

		cout << "What access should the new user have?";
		getline(cin, nUser.level);

		cout << "Username: ";
		getline(cin, nUser.username);
		if (nUser.username.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in usernames!\n";
			continue;
		}
		cout << "First Name: ";
		getline(cin, nUser.firstName);
		if (nUser.firstName.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in first name!\n";
			continue;
		}
		cout << "Last Name: ";
		getline(cin, nUser.lastName);
		if (nUser.lastName.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in last name!\n";
			continue;
		}
		cout << "Password: ";
		getline(cin, nUser.passwordHash);
		if (nUser.passwordHash.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in passwords!\n";
			continue;
		}

		cout << "Confirm Password: ";
		getline(cin, confirmPass);
		if (confirmPass.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in passwords!\n";
			continue;
		}
		if (nUser.passwordHash != confirmPass)
		{
			system("cls");
			cout << "Password doesn't match Confirm Password\nTry again please\n";
		}
	} while (nUser.passwordHash != confirmPass);

	nUser.id = DataBase::users.size() + 1;
	nUser.dateOfCreation = findCurrentTime().substr(0, findCurrentTime().size() - 1);
	nUser.dateOfLastChange = findCurrentTime().substr(0,findCurrentTime().size()-1);
	nUser.idOfCreator = logedUser.id;
	nUser.idOfLastEditor = logedUser.id;
	db.dataBaseAdd(nUser);
	cout << "User added successfully!";
	
	pressAnyKey();
	system("cls");
	mainMenu();
}
void updateUser()
{
	int userToBeChanged;
	system("cls");
	displayUsers();

	cout << "Which User would you like to change?\n";
	cin >> userToBeChanged;

	bool flag = false;
	string confirmPass = "";
	pm::types::User uUser = db.users[userToBeChanged - 1];
	do
	{
		//solves potentional getline problems
		cin.ignore(100, '\n');

		cout << "Change Level (press Enter if you want it unchanged)";
		char ch = _getch();
		cout << endl;
		if (ch != '\r')
			getline(cin, uUser.level);

		cout << "Change Username (press ENTER if you want it unchanged)";
		ch = _getch();
		cout << endl;
		if (ch != '\r')
			getline(cin, uUser.username);
		if (uUser.username.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in usernames!\n";
			continue;
		}

		cout << "Change First Name (press ENTER if you want it unchanged)";
		ch = _getch();
		cout << endl;
		if (ch != '\r')
			getline(cin, uUser.firstName);
		if (uUser.firstName.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in first name!\n";
			continue;
		}


		cout << "Change Last Name (press ENTER if you want it unchanged)";
		ch = _getch();
		cout << endl;
		if (ch != '\r')
			getline(cin, uUser.lastName);
		if (uUser.lastName.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in last name!\n";
			continue;
		}

		cout << "Change Password (press ENTER if you want it unchanged)";
		ch = _getch();
		cout << endl;
		if (ch != '\r')
			getline(cin, uUser.passwordHash);
		if (uUser.passwordHash.find(" ") != string::npos)
		{
			system("cls");
			cout << "Spaces aren't allowed! to use spaces in passwords!\n";
			continue;
		}
		flag = true;
	} while (!flag);

	uUser.dateOfLastChange = findCurrentTime().substr(0, findCurrentTime().size() - 1);
	uUser.idOfLastEditor = logedUser.id;
	db.dataBaseUpdate(uUser,userToBeChanged);
	cout << "User added successfully!";
	
	pressAnyKey();
	system("cls");
	mainMenu();
}
void deleteUser()
{
	cout << "Which user would you like to delete?";
	int choice;
	cin >> choice;
	db.dataBaseDelete(choice);
	mainMenu();
}

void createTeam()
{
	Team nTeam;

	//solves potentional getline problems
	cin.ignore(100, '\n');

	cout << "What title should the new team have?";
	getline(cin, nTeam.title);
	cout << endl;
	displayUsers();
	cout << "Which Users should be assigned to the new team?(write ID and write 0 to stop)\n";
	string ch;
	for(int i = 0; ch != "0"; i++)
	{
		cin >> ch;
		string chs = "";
		chs+=ch;
		nTeam.assignedUsers.push_back(db.users[stoi(chs)]);
	}

	nTeam.id = DataTeams::teams.size() + 1;
	nTeam.dateOfCreation = findCurrentTime().substr(0, findCurrentTime().size() - 1);
	nTeam.dateOfLastChange = findCurrentTime().substr(0, findCurrentTime().size() - 1);
	nTeam.creator = logedUser;
	nTeam.idOfLastEditor= logedUser.id;
	tdb.teamAdd(nTeam);
	cout << "User added successfully!";

	pressAnyKey();
	system("cls");
	mainMenu();
}
void updateTeam()
{
	int teamToBeChanged;
	system("cls");
	displayTeams();

	cout << "Which Team would you like to change?\n";
	cin >> teamToBeChanged;

	bool flag = false;
	Team nTeam = tdb.teams[teamToBeChanged - 1];
	do
	{
		//solves potentional getline problems
		cin.ignore(100, '\n');

		cout << "Change Title (press Enter if you want it unchanged)";
		char ch = _getch();
		cout << endl;
		if (ch != '\r')
			getline(cin, nTeam.title);

		cout << "Users assinged to this team: ";
		for (size_t i = 0; i < nTeam.assignedUsers.size(); i++)
		{
			cout << nTeam.assignedUsers[i].username << " ";
		}
		cout << endl << "Write the username of the users that need to be removed//added (press Enter if you want it unchanged)";
		ch = _getch();
		cout << endl;
		if (ch != '\r')
		{
			
			string input;
			while (true)
			{
				cin >> input;
				if (input == "0")
					break;
				bool flager = false;
				for (size_t i = 0; i < nTeam.assignedUsers.size(); i++)
				{
					if (toLowerCase(input) == toLowerCase(nTeam.assignedUsers[i].username))
					{
						flager = true;
						nTeam.assignedUsers.erase(nTeam.assignedUsers.begin() + i, nTeam.assignedUsers.begin() + i);
						nTeam.assignedUsers.pop_back();
						break;
					}
				}
				if (!flager)
				{
					pm::types::User userToBeAdded;
					for (size_t i = 0; i < db.users.size(); i++)
					{
						if (input == db.users[i].username)
							userToBeAdded = db.users[i];
					}

					nTeam.assignedUsers.push_back(userToBeAdded);
				}
			}
		}

		flag = true;
	} while (!flag);

	nTeam.dateOfLastChange = findCurrentTime().substr(0, findCurrentTime().size() - 1);
	nTeam.idOfLastEditor = logedUser.id;
	tdb.teamUpdate(nTeam, teamToBeChanged);
	cout << "Team changed!";

	pressAnyKey();
	system("cls");
	mainMenu();
}
void deleteTeam()
{
	displayTeams();
	cout << "Which team would you like to delete?";
	int choice;
	cin >> choice;
	tdb.teamDelete(choice);
	cout << "Team " << tdb.teams[choice - 1].title << " deleted!\n";
	pressAnyKey();
	mainMenu();
}

void displayTeams()
{
	cout << "ID | ";
	cout << "Title | ";
	cout << "Date of creation | ";
	cout << "Username of creator | ";
	cout << "Date last change | ";
	cout << "Username of last editor | ";
	cout << "(Assigned users) \n\n";
	for (size_t i = 0; i < tdb.teams.size(); i++)
	{
		if (!tdb.teams[i].deleted)
		cout << tdb.fullCredential(i) << endl;
	}
	cout << endl;
}

void displayUsers()
{
	cout << "ID | ";
	cout << "Level | ";
	cout << "Username | ";
	cout << "First name | ";
	cout << "Date of creation | ";
	cout << "Password | ";
	cout << "Id of creator | ";
	cout << "Date last change | ";
	cout << "Id of last editor \n\n";
	for (size_t i = 0; i < db.users.size(); i++)
	{
		if(!db.users[i].deleted)
		cout << db.fullCredential(i) << endl;
	}
	cout << endl;
}

void loginUser()
{
	string username;
	string pass;
	cout << "Log in \n";
	cout << "Username: ";
	getline(cin, username);

	cout << "Password: ";
	getline(cin, pass);

	bool userFound = false;
	int i = 0;
	for (size_t i = 0; i < db.users.size(); i++)
	{
		if (toLowerCase(username) + pass == toLowerCase(db.users[i].username) + db.users[i].passwordHash)
		{
			cout << "User has loged in successfully\n";
			logedUser = db.users[i];
			return;
		}
	}
	if (!userFound)
	{
		system("cls");
		cout << "Wrong cridentioals! Press any key to continue";
		loginUser();
	}
	else cout << "Unable to open file";
	pressAnyKey();
	
	system("cls");
	mainMenu();
}

void userManager()
{
	cout << "1. Add User\n";
	cout << "2. Change User\n";
	cout << "3. Delete User\n";
	cout << "4. Display All Users\n";
	cout << "5. Exit\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		createUser();
		break;
	case 2:
		updateUser();
		break;
	case 3:
		deleteUser();
		break;
	case 4:
		displayUsers();
		pressAnyKey();
		system("cls");
		userManager();
		break;
	case 5:
		system("cls");
		mainMenu();
		break;
	}
}
void teamManager()
{
	cout << "1. Add Team\n";
	cout << "2. Change Team\n";
	cout << "3. Delete Team\n";
	cout << "4. Display All Team\n";
	cout << "5. Exit\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		createTeam();
		break;
	case 2:
		updateTeam();
		break;
	case 3:
		deleteTeam();
		break;
	case 4:
		displayTeams();
		pressAnyKey();
		system("cls");
		teamManager();
		break;
	case 5:
		system("cls");
		mainMenu();
		break;
	}
}

void mainMenu()
{
	system("cls");
	cout << logedUser.username << " " << logedUser.level<<endl<<endl;
	if (toLowerCase(logedUser.level) == "admin")
	{
		cout << "1. User Manager\n";
		cout << "2. Team Manager\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			userManager();
			break;
		case 2:
			system("cls");
			teamManager();
			break;
		}
	}
}