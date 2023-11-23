//
// Created by Honor on 23.11.2023.
//

#ifndef VIRTUAL_KEYBOARD_WORKFLOW_H
#define VIRTUAL_KEYBOARD_WORKFLOW_H

#include "IWorkflow.h"

#include <vector>
#include <string>

namespace entity {
    class Workflow : public IWorkflow {
    public:
        Workflow();

        void enroll(const std::string &key, const std::string &appointment);

        void printPressing() override;

        void printWorkflow() override;

        void printCommandList() override;

        std::string getCommandOrFail(const std::string &key);

        void reassignKey(const std::string &key, const std::string &command);

    private:
        std::vector<std::pair<std::string, std::string>> m_sequencing;

        std::vector<std::pair<std::string, std::string>> m_commandList;
    };
}


#endif //VIRTUAL_KEYBOARD_WORKFLOW_H
