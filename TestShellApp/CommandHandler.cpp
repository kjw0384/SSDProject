#include <sstream>
#include <iostream>
#include "CommandHandler.h"
#include "IScenario.h"
#include "../TestScenario/TestScenario.h"

Result_e CommandHandler::runParse(const string& testScript) {
    vector<string> testScriptTokens = parser.splitTestScript(testScript);
    TestScenario testScenario;

    if (checker.isValidCommand(testScript, testScriptTokens) == false) {
        if (checker.isValidScenario(testScript, testScenario) == false) {
            return Result_e::FAIL;
        }
        command.type = "testcase";
        handleScenario(testScript, testScenario);
        return Result_e::SUCCESS;
    }

    CommandType_e commandType = parser.executeParse(testScriptTokens);
    command = parser.getCommand();

    if (commandType == CommandType_e::EXIT) {
        return Result_e::EXIT;
    }
    if (commandType == CommandType_e::HELP) {
        handleHelp();
    }
    return Result_e::SUCCESS;
}

Command CommandHandler::getCommand() {
    if (command.type.empty()) {
        throw std::exception();
    }
    return command;
}

void CommandHandler::handleHelp() {
    std::cout << "\n\n*** Command information.***\n\n";
    std::cout << "write [LBA] [data]: Write data to the LBA.\n";
    std::cout << "      [LBA] : 0~99 (decimal number).\n";
    std::cout << "      [data]: 0x00000000~0xFFFFFFFF (8-digital hexadecimal number with 0x prefix).\n\n";

    std::cout << "read [LBA]: Read data from LBA.\n";
    std::cout << "     [LBA]: 0~99 (decimal number).\n\n";

    std::cout << "fullwrite [data]: Write data from LBA 0 to LBA 99.\n";
    std::cout << "          [data]: 0x00000000~0xFFFFFFFF (8-digital hexadecimal number with 0x prefix).\n\n";

    std::cout << "fullread: Read data from LBA 0 to LBA 99.\n\n";

    std::cout << "erase [LBA]: [size]: Erase data from LBA for the given size.\n";
    std::cout << "      [LBA]: 0~99 (decimal number).\n";
    std::cout << "      [size]: 0~100 (decimal number).\n\n";

    std::cout << "erase_range [StartLBA]: [EndLBA]: Erase data from StartLBA to EndLBA-1.\n";
    std::cout << "            [StartLBA]: 0~99 (decimal number).\n";
    std::cout << "            [EndLBA]: 1~100 (decimal number).\n\n";
    
    std::cout << "exit: Exit the program.\n\n";
}

void CommandHandler::handleScenario(const string& testScenario, TestScenario& scenarioLib) {
    // Call DLL to get the scenario class
    scenario = scenarioLib.getScenario(testScenario);
}