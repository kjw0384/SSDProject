#include "WriteCommand.h"
#include "SSDDevice.h"

void WriteCommand::execute() {
    device->write(address, data);
}