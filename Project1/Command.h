#pragma once
#include "ShellStringParser.h"
#include "NANDDevice.h"

#define interface struct

using namespace std;

interface ShellCommand {
    ShellCommand(NANDDevice* _device)
        : device(_device) { }
public:
    virtual ~ShellCommand() {}

    virtual void execute() = 0;
    virtual ShellStringParserError parse(vector<string> inputCmdVec) = 0;

protected:
    NANDDevice* device;
};
