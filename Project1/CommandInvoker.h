#pragma once

#include "Command.h"

class CommandInvoker {
public:
      void setCommand(ShellCommand* cmd) {
        this->command = cmd;
    }

    void executeCommand() {
        if (command) {
            command->execute();
        }
    }

private:
    ShellCommand* command;
};