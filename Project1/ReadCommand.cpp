#include "ReadCommand.h"
#include "SSDDevice.h"

void ReadCommand::execute() {
    device->read(address);
}
