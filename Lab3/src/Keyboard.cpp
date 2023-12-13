//
// Created by Honor on 25.10.2023.
//

#include <utility>

#include "../headers/Keyboard.h"

using namespace entity;

Keyboard::Keyboard(Workflow workflow) : m_workflow(std::move(workflow)) {

}

void Keyboard::launch() {
    m_workflow.launch();
}
