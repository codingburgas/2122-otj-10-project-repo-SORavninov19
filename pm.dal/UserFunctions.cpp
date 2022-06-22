#include "pch.h"
#include "UserFunctions.h"

std::vector<pm::types::User> users;

size_t generateNewId()
{
	size_t maxId = 0;
	for (auto user : users)
	{
		if (user.id > maxId)
		{
			maxId = user.id;
		}
	}
}
void UserFunctions::create(pm:: types::User& user)
{
	auto it = std::find_if(users.begin(), users.end(),
		[&](pm::types::User u) {return u.email = user.email; });
	if (it != users.end())
	{
		throw "The user " + std::string(user.email) + " already exists!";
	}

	user.id = generateNewId();
	users.push_back(user);
}

pm::types::User UserFunctions::getById(size_t id)
{
	auto it = std::find_if(users.begin(), users.end(),
		[&](pm::types::User u) {return u.id = id; });
	if (it != users.end())
	{
		throw std::string("User with id") + std::to_string(id) + std::string(" was not found!";
	}
	return *it;
}

std::vector<pm::types::User> UserFunctions::getAll()
{
	return std::vector<pm::types::User>(users);
}

void UserFunctions::remove(size_t id)
{
	for (auto it = users.begin(); it != users.end(); it++)
	{
		if ((*it).id == id)
		{
			users.erase(it);
			return;
		}
	}
}

void UserFunctions::update(pm::types::User user)
{
	std::vector<pm::types::User>::iterator it;
	it = std::find_if(users.begin(), users.end(),
		[&](pm::types::User u) {return u.id = user.id});
	if (it == users.end())
	{
		throw "User with id" + std::to_string(user.id) + " was not found!";
	}
	auto& u = *it;
	u.firstName = user.firstName;
	u.lastName = user.lastName;
	u.email = user.email;
	u.age = user.age;


}

