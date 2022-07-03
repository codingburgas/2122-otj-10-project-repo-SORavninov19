#include <iostream>
#include "../pm.dal/dataBaseAccess.h"
#include "../pm.pl/menu.h"
int main()
{
	DataBase users;
	users.dataBaseOpen();
	loginUser();
	mainMenu();
}

