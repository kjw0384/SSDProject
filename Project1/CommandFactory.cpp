#include <algorithm>
#include <string>
#include "CommandFactory.h"
#include "ReadCommand.h"
#include "WriteCommand.h"
#include "EraseCommand.h"
#include "FlushCommand.h"


DeviceCommand* ShellCommandFactory::getCommand(NANDDevice* device, vector<string> inputCmdVec) {

    if (inputCmdVec.empty())
        return nullptr;
    
    DeviceCommand* commandPtr = nullptr;
    string command = toUpper(inputCmdVec[0]);
    if (command == "R") {
        commandPtr = new ReadCommand(device);
    }
    else if (command == "W") {
        commandPtr = new WriteCommand(device);
    }
    else if (command == "E") {
        commandPtr = new EraseCommand(device);
    }
    else if (command == "F") {
        commandPtr = new FlushCommand(device);
    }
    else
    {
        return nullptr;
    }

    if (commandPtr->parse(inputCmdVec) != ShellStringParserError::NO_ERROR)
        return nullptr;

    return commandPtr;
}

string ShellCommandFactory::toUpper(string inputStr) {
    std::transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::toupper);
    return inputStr;
}
