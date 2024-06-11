#pragma once

#include "Command.h"
#include "NANDDevice.h"

#include <string>
#include <iostream>


class WriteCommand : public DeviceCommand {
public:
    WriteCommand(NANDDevice* device)
        : DeviceCommand(device) {}
        
    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;

private:
    int address = -1;
    string data = "";
};