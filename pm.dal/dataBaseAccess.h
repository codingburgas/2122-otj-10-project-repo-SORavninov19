#pragma once
#include <fstream>
#include <vector>
#include "../pm.types/User.h"


std::vector<pm::types::User> dataBaseOpen();
void dataBaseDelete();
void dataBaseAdd();
void dataBaseUpdate();