//
// Created by Honor on 04.12.2023.
//

#include "../headers/UserRepository.h"
#include "../headers/IRepository.h"
#include "../headers/User.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>

using namespace entity;

UserRepository::UserRepository(std::string reposPath) :
        m_reposPath{std::move(reposPath)} {}

std::string UserRepository::getReposPath() {
    return m_reposPath;
}

std::vector<User> UserRepository::getAll() {
    std::vector<User> users;
    std::string user;

    std::ifstream inputFile(m_reposPath);

    if (inputFile.is_open()) {
        while (std::getline(inputFile, user)) {
            size_t idSeparator = user.find("; ");
            size_t nameSeparator = user.find("; ", idSeparator + 2);
            size_t loginSeparator = user.find("; ", nameSeparator + 2);

            if (idSeparator == std::string::npos || nameSeparator == std::string::npos ||
                loginSeparator == std::string::npos) {
                continue;
            }

            int userId = std::stoi(user.substr(0, idSeparator));
            std::string userName = user.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
            std::string userLogin = user.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);
            std::string userPassword = user.substr(loginSeparator + 2, user.length() - loginSeparator - 2);

            users.emplace_back(userId, userName, userLogin, userPassword);
        }
    }

    inputFile.close();

    return users;
}

void UserRepository::add(User user) {
    std::ofstream outputFile;
    outputFile.open(m_reposPath, std::ios::app);
    if (outputFile.is_open()) {
        outputFile << user.getId() << "; "
                   << user.getName() << "; "
                   << user.getLogin() << "; "
                   << user.getPassword()
                   << std::endl;
    }
    outputFile.close();
}

void UserRepository::remote(User user) {
    std::vector<User> users;
    std::string userString;
    std::string fileText;

    std::ifstream inputFile(m_reposPath);

    if (inputFile.is_open()) {
        while (std::getline(inputFile, userString)) {
            size_t idSeparator = userString.find("; ");

            if (idSeparator == std::string::npos) {
                continue;
            }

            int tempUserId = std::stoi(userString.substr(0, idSeparator));

            if (tempUserId != user.getId()) {
                fileText.insert(fileText.size(), userString);
                fileText.insert(fileText.size(), "\n");
            }
        }
    }

    inputFile.close();

    std::ofstream outputFile;
    outputFile.open(m_reposPath);
    if (outputFile.is_open()) {
        outputFile << fileText;
    }
    outputFile.close();
}

void UserRepository::update(User user) {
    std::vector<User> users;
    std::string userString;
    std::string updatedUser = std::to_string(user.getId()) + "; "
                              + user.getName() + "; "
                              + user.getLogin() + "; "
                              + user.getPassword() + "\n";
    std::string fileText;

    std::ifstream inputFile(m_reposPath);

    if (inputFile.is_open()) {
        while (std::getline(inputFile, userString)) {
            size_t idSeparator = userString.find("; ");

            if (idSeparator == std::string::npos) {
                continue;
            }

            int tempUserId = std::stoi(userString.substr(0, idSeparator));

            if (tempUserId != user.getId()) {
                fileText.insert(fileText.size(), userString);
                fileText.insert(fileText.size(), "\n");
            } else {
                fileText.insert(fileText.size(), updatedUser);
            }
        }
    }

    inputFile.close();

    std::ofstream outputFile;
    outputFile.open(m_reposPath);
    if (outputFile.is_open()) {
        outputFile << fileText;
    }
    outputFile.close();
}

User UserRepository::getById(int id) {
    User user = User(0, "", "", "");
    std::string userString;

    std::ifstream inputFile(m_reposPath);

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

            if (userId != id) {
                continue;
            }

            std::string userName = userString.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
            std::string userLogin = userString.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);
            std::string userPassword = userString.substr(loginSeparator + 2, userString.length() - loginSeparator - 2);

            user = User(userId, userName, userLogin, userPassword);
        }
    }

    inputFile.close();

    return user;
}

User UserRepository::getByLogin(std::string login) {
    User user = User(0, "", "", "");
    std::string userString;

    std::ifstream inputFile(m_reposPath);

    if (inputFile.is_open()) {
        while (std::getline(inputFile, userString)) {
            size_t idSeparator = userString.find("; ");
            size_t nameSeparator = userString.find("; ", idSeparator + 2);
            size_t loginSeparator = userString.find("; ", nameSeparator + 2);

            if (idSeparator == std::string::npos || nameSeparator == std::string::npos ||
                loginSeparator == std::string::npos) {
                continue;
            }

            std::string userLogin = userString.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);

            if (userLogin != login) {
                continue;
            }

            int userId = std::stoi(userString.substr(0, idSeparator));
            std::string userName = userString.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
            std::string userPassword = userString.substr(loginSeparator + 2, userString.length() - loginSeparator - 2);

            user = User(userId, userName, userLogin, userPassword);
        }
    }

    inputFile.close();

    return user;
}
