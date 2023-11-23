//
// Created by Honor on 23.11.2023.
//

#include "../headers/Workflow.h"

#include <iostream>
#include <string>

using namespace entity;

Workflow::Workflow() {
    m_commandList.emplace_back("Upper Case", "Caps Lock");
    m_commandList.emplace_back("Tabulation", "Tab");
    m_commandList.emplace_back("Enter", "Enter");
    m_commandList.emplace_back("Back", "Backspace");
}

void Workflow::enroll(const std::string &key, const std::string &appointment) {
    m_sequencing.emplace_back(key, appointment);
    printPressing();
}

void Workflow::printPressing() {
    std::cout << m_sequencing[m_sequencing.size() - 1].first
              << ": " << m_sequencing[m_sequencing.size() - 1].second
              << std::endl;
}

void Workflow::printWorkflow() {
    std::cout << "Temp WorkFlow" << std::endl;
    for (const auto& press: m_sequencing) {
        std::cout << "'" << press.first << "' ";
    }
    std::cout << std::endl;
}

void Workflow::printCommandList() {
    std::cout << "Temp Command List" << std::endl;
    for (const auto& command: m_commandList) {
        std::cout << "Command: " << command.first << ", key: " << command.second << std::endl;
    }
}

void Workflow::reassignKey(const std::string &key, const std::string &command) {
    for(int i = 0; i < m_commandList.size(); i++) {
        if(m_commandList[i].first == command) {
            m_commandList[i].second = key;
            return;
        }
    }
    m_commandList.emplace_back(command, key);
}

std::string Workflow::getCommandOrFail(const std::string &key) {
    for (const auto& commandItem: m_commandList) {
        if (commandItem.second == key) {
            return commandItem.first;
        }
    }
    return "Unknown command";
}