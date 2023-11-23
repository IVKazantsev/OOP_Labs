#include <iostream>

#include "headers/Keyboard.h"
#include "headers/Workflow.h"

using namespace entity;

int main() {
    Workflow workflow;
    Keyboard keyboard(workflow);
    keyboard.PressKey("Caps Lock");
    keyboard.PressKey("h");
    keyboard.PressKey("Caps Lock");
    keyboard.PressKey("e");
    keyboard.PressKey("l");
    keyboard.PressKey("l");
    keyboard.PressKey("o");

    keyboard.PressKey("Tab");
    keyboard.PressKeys("Shift+A");
    keyboard.PressKey("+");

    keyboard.PressKey("Enter");
    keyboard.PressKeys("Enter");
    keyboard.PressKey("!");
    keyboard.PressKey("Backspace");

    keyboard.printCommandList();

    keyboard.reassignKey("P", "Back");
    keyboard.reassignKey("Backspace", "Return");

    keyboard.printWorkflow();
    keyboard.printCommandList();
    return 0;
}
