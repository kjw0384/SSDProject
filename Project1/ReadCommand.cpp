#include "ReadCommand.h"
#include "NANDDevice.h"

void ReadCommand::execute() {
    device->read(address);
}
