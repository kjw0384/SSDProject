#include "EraseCommand.h"
#include "NANDDevice.h"

void EraseCommand::execute() {
	device->erase(address, size);
}