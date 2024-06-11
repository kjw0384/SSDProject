#include <iostream>
#include <memory>
#include <vector>

#include "CommandFactory.h"
#include "CommandInvoker.h"
#include "EraseCommand.h"
#include "FlushCommand.h"
#include "NANDDevice.h"
#include "ReadCommand.h"
#include "ShellStringParser.h"
#include "WriteCommand.h"

int main(int argc, char *argv[])
{
    try
    {
        vector<string> arguments;
        for (int i = 1; i < argc; i++)
        {
            arguments.push_back(argv[i]);
        }

        NANDDevice device;
        CommandInvoker invoker;

        ShellCommandFactory factory = ShellCommandFactory::getInstance();
        DeviceCommand *command = factory.getCommand(&device, arguments);
        if (command == nullptr)
            return 1;

        invoker.setCommand(command);
        invoker.executeCommand();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
