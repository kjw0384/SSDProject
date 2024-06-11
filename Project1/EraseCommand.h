#pragma once

#include "Command.h"
#include "NANDDevice.h"

#include <iostream>
#include <string>

class EraseCommand : public DeviceCommand
{
  public:
    EraseCommand(NANDDevice *device) : DeviceCommand(device)
    {
    }

    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;

  private:
    int address = -1;
    int size = -1;
};
