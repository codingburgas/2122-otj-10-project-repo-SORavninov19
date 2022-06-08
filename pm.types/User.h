#pragma once
#include <string>

namespace pm::types
{
	struct user
	{
		size_t id;
		std::string firstName;
		std::string lastName;
		std::string email;
		uint8_t age;
		std::string passwordHash;
	}
}