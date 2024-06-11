#pragma once
#include "ShellStringParser.h"
#include "NANDDevice.h"

#define interface struct

using namespace std;

interface DeviceCommand {
    DeviceCommand(NANDDevice* _device)
        : device(_device) { }
public:
    virtual ~DeviceCommand() {}

    virtual void execute() = 0;
    virtual ShellStringParserError parse(vector<string> inputCmdVec) = 0;

protected:
    NANDDevice* device;
};
