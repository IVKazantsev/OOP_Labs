//
// Created by Honor on 25.10.2023.
//

#ifndef VIRTUAL_KEYBOARD_KEYBOARD_H
#define VIRTUAL_KEYBOARD_KEYBOARD_H

#include "IKeyboard.h"
#include "Workflow.h"

#include <iostream>
#include <string>

namespace entity {
    class Keyboard : public IKeyboard {
    public:
        explicit Keyboard(Workflow workflow);

        void PressKey(const std::string &key) override;

        void PressKeys(const std::string &keys) override;

        void printWorkflow() override;

        void printCommandList() override;

        void reassignKey(const std::string &key, const std::string &command) override;

    private:
        Workflow m_workflow;
    };
}


#endif //VIRTUAL_KEYBOARD_KEYBOARD_H
