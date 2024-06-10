#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <string>
#include <iostream>


class FlushCommand : public Command {
public:
    FlushCommand(NANDDevice* device)
        : Command(device) {}

    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;
};