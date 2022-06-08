#pragma once
#include "pch.h"
#include "../pm.dal/UserStore.h"
#include <vector>
namespace pm::bll
{
	struct UserManager
	{
		pm::dal::UserStore m_userStore;
		std::string hashString(std::string str);
		void registerUser(std::string firstName, std::string lastName, uint8_t age, std::string email, std::string password);
		pm::types::user loginUser(std::string username, std::string password);
		std::vector<pm::types::user> getRegisteredUser();
	
		void seedDatabase();

		void removeUser(size_t id);

		void updateUser(pm::types::user);
	};
}