//
// Created by Honor on 04.12.2023.
//

#include "../headers/User.h"

#include <string>
#include <utility>

using namespace entity;

User::User(const int &id,
           std::string name,
           std::string login,
           std::string password)
        : m_id{id},
          m_name{std::move(name)},
          m_login{std::move(login)},
          m_password{std::move(password)} {}

int User::getId() const {
    return m_id;
}

std::string User::getLogin() const {
    return m_login;
}

[[maybe_unused]] void User::setLogin(const std::string &login) {
    m_login = login;
}

std::string User::getPassword() const {
    return m_password;
}

[[maybe_unused]] void User::setPassword(const std::string &password) {
    m_password = password;
}

std::string User::getName() const {
    return m_name;
}

[[maybe_unused]] void User::setName(const std::string &name) {
    m_name = name;
}