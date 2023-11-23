//
// Created by Honor on 23.11.2023.
//

#ifndef VIRTUAL_KEYBOARD_IWORKFLOW_H
#define VIRTUAL_KEYBOARD_IWORKFLOW_H

#include <string>

namespace entity {
    class IWorkflow {
    public:
        virtual void enroll(const std::string &key, const std::string &appointment) = 0;

        virtual void printPressing() = 0;

        virtual void printWorkflow() = 0;

        virtual void printCommandList() = 0;

        virtual void reassignKey(const std::string &key, const std::string &command) = 0;
    };
}

#endif //VIRTUAL_KEYBOARD_IWORKFLOW_H