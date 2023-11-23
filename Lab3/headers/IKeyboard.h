//
// Created by Honor on 23.11.2023.
//

#ifndef VIRTUAL_KEYBOARD_IKEYBOARD_H
#define VIRTUAL_KEYBOARD_IKEYBOARD_H

#include <string>

namespace entity {
    class IKeyboard {
    public:
        virtual void PressKey(const std::string &key) = 0;

        virtual void PressKeys(const std::string &keys) = 0;

        virtual void printWorkflow() = 0;

        virtual void printCommandList() = 0;

        virtual void reassignKey(const std::string &key, const std::string &command) = 0;
    };
}

#endif //VIRTUAL_KEYBOARD_IKEYBOARD_H
