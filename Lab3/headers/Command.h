//
// Created by Honor on 13.12.2023.
//

#ifndef VIRTUAL_KEYBOARD_COMMAND_H
#define VIRTUAL_KEYBOARD_COMMAND_H

#include "ICommand.h"

namespace entity {
    class Command : public ICommand {
    public:
        Command(std::string key, std::string action);

        std::string getKey() override;

        std::string getAction() override;

        void setKey(const std::string &key) override;

    private:
        std::string m_key;
        std::string m_action;
    };
}

#endif //VIRTUAL_KEYBOARD_COMMAND_H
