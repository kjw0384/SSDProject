#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <string>
#include <iostream>


class FlushCommand : public ShellCommand {
private:
    NANDDevice* device;

public:
    FlushCommand(NANDDevice* device)
        : device(device) {}

    void execute() override;
};