#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../pm.dal/dataBaseAccess.h"
#include "../pm.dal/teams.h"
#include "../pm.types/User.h"
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <conio.h>
using namespace std;

extern pm::types::User logedUser;

void pressAnyKey();

void createUser();
void updateUser();
void deleteUser();

void createTeam();

void displayUsers();

void loginUser();

void mainMenu();