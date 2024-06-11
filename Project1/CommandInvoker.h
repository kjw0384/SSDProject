#pragma once

#include "Command.h"

class CommandInvoker
{
  public:
    void setCommand(DeviceCommand *cmd)
    {
        this->command = cmd;
    }

    void executeCommand()
    {
        if (command)
        {
            command->execute();
        }
    }

  private:
    DeviceCommand *command;
};
