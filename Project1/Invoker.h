#pragma once
#include "Command.h"
#include <memory>

class Invoker {
private:
    Command* command;
public:
      void setCommand(Command* cmd) {
        this->command = cmd;
    }

    void executeCommand() {
        if (command) {
            command->execute();
        }
    }
};