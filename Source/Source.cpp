#include <iostream>
#include "../pm.dal/dataBaseAccess.h"
#include "../pm.dal/teams.h"
#include "../pm.pl/menu.h"
int main()
{
	DataBase users;
	DataTeams team;
	users.dataBaseOpen();
	team.teamsDataBaseOpen();
	/*loginUser();
	mainMenu();*/
	createTeam();


}

