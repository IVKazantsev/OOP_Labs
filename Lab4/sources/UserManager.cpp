//
// Created by Honor on 04.12.2023.
//

#include "../headers/UserManager.h"
#include "../headers/User.h"
#include "../headers/UserRepository.h"

#include <fstream>

using namespace entity;

UserManager::UserManager(UserRepository &repos) : m_repos{repos}, m_user{nullptr} {}

void UserManager::signIn(User user) {
    if (m_user != nullptr) {
        return;
    }

    std::string userString;

    std::ifstream inputFile(m_repos.getReposPath());

    if (inputFile.is_open()) {
        while (std::getline(inputFile, userString)) {
            size_t idSeparator = userString.find("; ");
            size_t nameSeparator = userString.find("; ", idSeparator + 2);
            size_t loginSeparator = userString.find("; ", nameSeparator + 2);

            if (idSeparator == std::string::npos || nameSeparator == std::string::npos ||
                loginSeparator == std::string::npos) {
                continue;
            }

            int userId = std::stoi(userString.substr(0, idSeparator));
            std::string userLogin = userString.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);
            std::string userName = userString.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
            std::string userPassword = userString.substr(loginSeparator + 2, userString.length() - loginSeparator - 2);

            if (userId != user.getId()
                || userName != user.getName()
                || userLogin != user.getLogin()
                || userPassword != user.getPassword()) {
                continue;
            }

            m_user = new User(userId, userName, userLogin, userPassword);
        }
    }

    inputFile.close();
}

void UserManager::signOut(User user) {
    m_user = nullptr;
}

bool UserManager::isAuthorized() {
    return m_user == nullptr;
}
