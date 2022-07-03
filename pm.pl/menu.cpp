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
	nTeam.idOfCreator = logedUser.id;
	nTeam.idOfLastEditor= logedUser.id;
	tdb.teamAdd(nTeam);
	cout << "User added successfully!";

	pressAnyKey();
	system("cls");
	mainMenu();
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
	cout << "Id of last editor | ";
	cout << "Deleted\n";
	for (size_t i = 0; i < db.users.size(); i++)
	{
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
			cout << "User has loged in successfully";
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

void mainMenu()
{
	system("cls");
	cout << logedUser.username << " " << logedUser.level<<endl<<endl;

	if (toLowerCase(logedUser.level) == "admin")
	{
		cout << "1. Add User\n";
		cout << "2. Change User\n";
		cout << "3. Delete User\n";
	}
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
	}
}