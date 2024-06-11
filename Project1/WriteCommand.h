#pragma once

#include "Command.h"
#include "NANDDevice.h"

#include <iostream>
#include <string>

class WriteCommand : public DeviceCommand
{
  private:
    int address = -1;
    string data = "";

  public:
    WriteCommand(NANDDevice *device) : DeviceCommand(device)
    {
    }

    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;
};
