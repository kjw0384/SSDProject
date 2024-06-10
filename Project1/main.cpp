#include <memory>
#include <iostream>
#include <vector>

#include "Invoker.h"
#include "NANDDevice.h"
#include "ReadCommand.h"
#include "WriteCommand.h"
#include "EraseCommand.h"
#include "FlushCommand.h"
#include "ShellStringParser.h"

int main(int argc, char* argv[]) {
    try {
        vector<string> arguments;
        for (int i = 1; i < argc; i++)
        {
            arguments.push_back(argv[i]);
        }
        ShellStringParser parser;
        parser.validCheck(arguments);

        string command = argv[1];

        NANDDevice device;
        Invoker invoker;

        if (command == "R" || command == "r") {
            int adress = stoi(argv[2]);
            invoker.setCommand(new ReadCommand(&device, adress));
            invoker.executeCommand();
        }
        if (command == "W" || command == "w") {
            int adress = stoi(argv[2]);
            string data = argv[3];
            invoker.setCommand(new WriteCommand(&device, adress, data));
            invoker.executeCommand();
        }
        if (command == "E" || command == "e") {
            int adress = stoi(argv[2]);
            int size = stoi(argv[3]);
            invoker.setCommand(new EraseCommand(&device, adress, size));
            invoker.executeCommand();
        }
        if (command == "F" || command == "f") {
            invoker.setCommand(new FlushCommand(&device));
            invoker.executeCommand();
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
