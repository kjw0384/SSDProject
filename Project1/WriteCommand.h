#pragma once
#include "Command.h"
#include "SSDDevice.h"
#include <string>
#include <iostream>

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