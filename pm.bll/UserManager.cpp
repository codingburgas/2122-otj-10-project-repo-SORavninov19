#pragma once
#include "UserManager.h"

void pm::bll::UserManager::registerUser(std::string firstName, std::string lastName, uint8_t age, std::string email, std::string password)
{
	pm::types::user user;

	user.firstName = firstName;
	user.lastName = lastName;
	user.email = email;
	user.age = age;
	user.passwordHash = hashString(password);

	m_userStore.create(user);
}

pm::types::user pm::bll::UserManager::loginUser(std::string username, std::string password)
{
	auto user = m_userStore.getByEmail(username);

	std::string passHash = hashString(password);

	if (user.passwordHash != passHash)
	{
		throw std::logic_error("Invalid Password");
	}
	return user;
}

