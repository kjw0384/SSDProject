#pragma once
#include "ShellStringParser.h"
#include "NANDDevice.h"

#define interface struct

using namespace std;

class Command {
public:
    Command(NANDDevice* _device)
        : device(_device) { }
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual ShellStringParserError parse(vector<string> inputCmdVec) = 0;

protected:
    NANDDevice* device;
};
