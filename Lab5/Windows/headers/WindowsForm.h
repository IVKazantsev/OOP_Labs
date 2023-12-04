//
// Created by Honor on 04.12.2023.
//

#ifndef ABSTRACT_FACTORY_WINDOWSFORM_H
#define ABSTRACT_FACTORY_WINDOWSFORM_H

#include "../../Controls/Form.h"

namespace factories {
    class WindowsForm : public Form {
        void setPosition() override;

        void getPosition() override;

        void addControl() override;
    };
}

#endif //ABSTRACT_FACTORY_WINDOWSFORM_H
