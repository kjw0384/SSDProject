#pragma once
#include "Command.h"
#include "NANDDevice.h"
#include <string>
#include <iostream>

class WriteCommand : public Command {
private:
    NANDDevice* device;
    int address;
    string data;

public:
    WriteCommand(NANDDevice* device, const int address, const string& data)
        : device(device), address(address), data(data) {}

    void execute() override;
};