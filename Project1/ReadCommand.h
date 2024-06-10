#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <string>
#include <iostream>


class ReadCommand : public Command {
private:
    int address = -1;

public:
    ReadCommand(NANDDevice* device)
        : Command(device) {}

    void execute() override;

    ShellStringParserError parse(vector<string> inputCmdVec) override;
};