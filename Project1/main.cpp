int main(void) {

}

#include "Invoker.h"
#include "NANDDevice.h"
#include "ReadCommand.h"
#include "WriteCommand.h"
#include <memory>
/*
int main() {
    NANDDevice device;

    Invoker invoker;
    invoker.setCommand(new ReadCommand(&device, 1));
    invoker.executeCommand();

    invoker.setCommand(new WriteCommand(&device, 2, "0xAAAAAAAA"));
    invoker.executeCommand();

    return 0;
}*/
