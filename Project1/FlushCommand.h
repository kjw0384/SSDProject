#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <string>
#include <iostream>


class FlushCommand : public ShellCommand {
private:
    NANDDevice* device;

    FlushCommand(NANDDevice* device)
        : Command(device) {}

    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;
};