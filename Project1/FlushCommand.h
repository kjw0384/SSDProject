#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <string>
#include <iostream>


class FlushCommand : public Command {
private:
    NANDDevice* device;

public:
    FlushCommand(NANDDevice* device)
        : device(device) {}

    void execute() override;
};