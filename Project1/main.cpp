#include <memory>
#include <iostream>
#include <vector>

#include "Invoker.h"
#include "NANDDevice.h"
#include "ReadCommand.h"
#include "WriteCommand.h"
#include "EraseCommand.h"
#include "ShellStringParser.h"

int main(int argc, char* argv[]) {
    vector<string> arguments;
    for (int i = 1; i < argc; i++)
    {
        arguments.push_back(argv[i]);
    }
    ShellStringParser parser;
    parser.validCheck(arguments);

    string command = argv[1];
    int adress = stoi(argv[2]);

    NANDDevice device;
    Invoker invoker;

    if (command == "R" || command == "r") {
        invoker.setCommand(new ReadCommand(&device, adress));
        invoker.executeCommand();
    }
    if (command == "W" || command == "w") {
        string data = argv[3];
        invoker.setCommand(new WriteCommand(&device, adress, data));
        invoker.executeCommand();
    }
    if (command == "E" || command == "e") {
        int size = stoi(argv[3]);
        invoker.setCommand(new EraseCommand(&device, adress, size));
        invoker.executeCommand();
    }
}
