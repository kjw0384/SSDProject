#include "FlushCommand.h"
#include "NANDDevice.h"

void FlushCommand::execute() {
    device->flush();
}
