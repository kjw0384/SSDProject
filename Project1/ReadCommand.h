#pragma once
#include <string>
#include <iostream>

#include "Command.h"
#include "SSDDevice.h"

class ReadCommand : public Command {
private:
    SSDDevice* device;
    int address;

public:
    ReadCommand(SSDDevice* device, const int address)
        : device(device), address(address) {}

    void execute() override;
};