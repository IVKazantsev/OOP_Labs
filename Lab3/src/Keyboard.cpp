//
// Created by Honor on 25.10.2023.
//

#include "../headers/Keyboard.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace entity;

Keyboard::Keyboard(Workflow workflow) : m_workflow(workflow) {

};

void Keyboard::PressKey(const std::string &key) {
    if (key.length() == 0) {
        std::cout << "Вы ввели не клавишу";
        return;
    } else if (key.length() > 1) {
        m_workflow.enroll(key, m_workflow.getCommandOrFail(key));
        return;
    }

    m_workflow.enroll(key, "key");
}

void Keyboard::PressKeys(const std::string &keys) {
    if (find(keys.begin(), keys.end(), '+') != keys.end()) {
        m_workflow.enroll(keys, "combination");
        return;
    }
    PressKey(keys);
}

void Keyboard::printWorkflow() {
    m_workflow.printWorkflow();
}

void Keyboard::printCommandList() {
    m_workflow.printCommandList();
}

void Keyboard::reassignKey(const std::string &key, const std::string &command) {
    m_workflow.reassignKey(key, command);
}
