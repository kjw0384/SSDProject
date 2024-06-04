#pragma once
#include "Command.h"
#include <string>
#include <iostream>

class SSDDevice;

class ReadCommand : public Command {
private:
    SSDDevice* device;
    int address;

public:
    ReadCommand(SSDDevice* device, const int address)
        : device(device), address(address) {}

    void execute() override;
};