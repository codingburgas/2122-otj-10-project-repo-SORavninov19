#pragma once
#include <string>
#include <stdio.h>
#include <time.h>

namespace pm::types
{
	struct User
	{
		size_t id;
		std::string firstName;
		std::string lastName;
		std::string email;
		uint8_t age;
		std::string dateOfCreation;
		std::string passwordHash;
	};
}