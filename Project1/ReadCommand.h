#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <string>
#include <iostream>


class ReadCommand : public Command {
private:
    NANDDevice* device;
    int address;

public:
    ReadCommand(NANDDevice* device, const int address)
        : device(device), address(address) {}

    void execute() override;
};