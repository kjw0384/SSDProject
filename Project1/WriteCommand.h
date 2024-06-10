#pragma once

#include "Command.h"
#include "NANDDevice.h"

#include <string>
#include <iostream>


class WriteCommand : public ShellCommand {
private:
    int address = -1;
    string data = "";

public:
    WriteCommand(NANDDevice* device)
        : Command(device) {}
        
    void execute() override;
    ShellStringParserError parse(vector<string> inputCmdVec) override;

};