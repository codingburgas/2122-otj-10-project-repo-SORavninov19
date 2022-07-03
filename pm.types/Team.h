#pragma once
#include <string>
#include <vector>
#include "User.h"
struct Team
{
	size_t id;
	std::string title;
	std::string dateOfCreation;
	size_t idOfCreator;
	std::string dateOfLastChange;
	size_t idOfLastEditor;
	pm::types::User creator;
	std::vector <pm::types::User> assignedUsers;
	bool deleted = false;
};