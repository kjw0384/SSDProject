#pragma once
#include "Command.h"
#include <string>
#include <iostream>

class SSDDevice;

class WriteCommand : public Command {
private:
    SSDDevice* device;
    int address;
    string data;

public:
    WriteCommand(SSDDevice* device, const int address, const string& data)
        : device(device), address(address), data(data) {}

    void execute() override;
};