#include <iostream>
#include "../pm.dal/dataBaseAccess.h"
#include "../pm.types/User.h"

int main()
{
	DataBase users;
	users.dataBaseOpen();
	users.dataBaseDelete(1);
	
}

