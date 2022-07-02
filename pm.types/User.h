#pragma once
#include <string>
#include <stdio.h>
#include <time.h>

namespace pm::types
{
	struct User
	{
		size_t id;
		std::string level;
		std::string username;
		std::string firstName;
		std::string lastName;
		std::string dateOfCreation;
		std::string passwordHash;
		size_t idOfCreator;
		std::string dateOfLastChange;
		size_t idOfLastEditor;
		bool deleted = false;
	};
}