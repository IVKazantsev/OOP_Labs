#include <iostream>

#include "headers/Keyboard.h"
#include "headers/Workflow.h"

using namespace entity;

int main() {
    Workflow workflow;
    Keyboard keyboard(workflow);
    keyboard.launch();
    return 0;
}
