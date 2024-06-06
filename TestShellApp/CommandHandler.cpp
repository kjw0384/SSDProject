#include "CommandHandler.h"
#include <sstream>
#include <iostream>

Result_e CommandHandler::runCommand(const string& testScript) {

    if (checker.isValidCommand(testScript) == false) {
        return Result_e::FAIL;
    }

    CommandType_e commandType=parser.executeParse(testScript);
    cmd = parser.getTestCmd();

    if (commandType == CommandType_e::EXIT) {
        return Result_e::EXIT;
    }
    if (commandType == CommandType_e::HELP) {
        handleHelp();
    }
    return Result_e::SUCCESS;
}

Command CommandHandler::getCommand() {
    return cmd;
}

void CommandHandler::handleHelp() {
    std::cout << "Command information.\n\n";
    std::cout << "write [LBA] [data]: Write data to the LBA.\n";
    std::cout << "      [LBA] : 0~99 (decimal number).\n";
    std::cout << "      [data]: 0x00000000~0xFFFFFFFF (8-digital hexadecimal number with 0x prefix).\n\n";

    std::cout << "read [LBA]: Read data from LBA.\n";
    std::cout << "     [LBA]: 0~99 (decimal number).\n\n";

    std::cout << "fullwrite [data]: Write data from LBA 0 to LBA 99.\n";
    std::cout << "          [data]: 0x00000000~0xFFFFFFFF (8-digital hexadecimal number with 0x prefix).\n\n";

    std::cout << "fullread: Read data from LBA 0 to LBA 99.\n\n";

    std::cout << "exit: Exit the program.\n";
}