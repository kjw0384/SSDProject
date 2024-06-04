#include "WriteCommand.h"
#include "NANDDevice.h"

void WriteCommand::execute() {
    device->write(address, data);
}