#include <iostream>
#include "../pm.dal/dataBaseAccess.h"
#include "../pm.types/User.h"

int main()
{
	DataBase users;
	users.dataBaseOpen();
	pm::types::User nUser = {14,"user","torna","3","ravninov","now","ler",1,"now",1,false};
	users.dataBaseUpdate(nUser,3);
}

