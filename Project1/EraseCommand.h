#pragma once

#include "Command.h"
#include "NANDDevice.h"

#include <string>
#include <iostream>

class EraseCommand : public ShellCommand {
private:
    NANDDevice* device;
    int address;
    int size;

public:
    EraseCommand(NANDDevice* device, const int address, const int size)
        : device(device), address(address), size(size) {}

    void execute() override;
};