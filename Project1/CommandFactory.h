#pragma once
#include <string>
#include <vector>

#include "Command.h"
#include "NANDDevice.h"

class ShellCommandFactory
{
  public:
    static ShellCommandFactory &getInstance()
    {
        static ShellCommandFactory instance{};
        return instance;
    }
    DeviceCommand *getCommand(NANDDevice *device, vector<string> inputCommandVec);

  private:
    ShellCommandFactory()
    {
    }
    string toUpper(string inputStr);
};
