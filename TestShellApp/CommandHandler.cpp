#include <sstream>
#include <iostream>
#include "CommandHandler.h"
#include "IScenario.h"
#include "../TestScenario/TestScenario.h"

Result_e CommandHandler::runCommand(const string& testScript) {
    TestScenario testScenario;
    if (checker.isValidCommand(testScript) == false) {
        if (checker.isValidScenario(testScript, testScenario) == false) {
            return Result_e::FAIL;
        }
        handleScenario(testScript, testScenario);
        return Result_e::SUCCESS;
    }

    CommandType_e commandType = parser.executeParse(testScript);
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

void CommandHandler::handleScenario(const string& testScenario, TestScenario& scenarioLib) {
    // Call DLL to get the scenario class
    //IScenario* scenario = scenarioLib.getScenario(testScenario);
    scenario = scenarioLib.getScenario(testScenario);
    scenario->run();
}