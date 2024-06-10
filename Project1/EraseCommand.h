#pragma once

#include "Command.h"
#include "NANDDevice.h"

#include <string>
#include <iostream>

class EraseCommand : public Command {
private:
    int address = -1;
    int size = -1;

public:
    EraseCommand(NANDDevice* device)
        : Command(device) {}

    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;
};