#pragma once
#include "Command.h"
#include "SSDDevice.h"
#include <string>
#include <iostream>

class ReadCommand : public Command {
private:
    SSDDevice* device;
    int address;

public:
    ReadCommand(SSDDevice* device, const int address)
        : device(device), address(address) {}

    void execute() override;
};