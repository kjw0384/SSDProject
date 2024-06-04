#pragma once
#include <string>
#include <iostream>

#include "Command.h"
#include "SSDDevice.h"

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