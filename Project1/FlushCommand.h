#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <iostream>
#include <string>

class FlushCommand : public DeviceCommand
{
  public:
    FlushCommand(NANDDevice *device) : DeviceCommand(device)
    {
    }

    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;

  private:
    NANDDevice *device;
};
