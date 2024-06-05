#include <memory>
#include <iostream>1
#include <vector>

#include "Invoker.h"
#include "NANDDevice.h"
#include "ReadCommand.h"
#include "WriteCommand.h"
#include "ShellStringParser.h"

int main(int argc, char* argv[]) {
    vector<string> arguments;
    for (int i = 1; i < argc; i++)
    {
        arguments.push_back(argv[i]);
    }
    ShellStringParser parser;
    parser.validCheck(arguments);
}

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
