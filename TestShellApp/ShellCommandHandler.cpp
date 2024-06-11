#include <sstream>
#include <iostream>
#include "ShellCommandHandler.h"
#include "IScenario.h"
#include "../TestScenario/TestScenarioAPI.h"
#include "Logger.h"

Result_e ShellCommandHandler::exportCmdWithString(const string& inputString, ShellCommand* retCmd) {
    vector<string> testScriptTokens = m_Parser.splitTestScript(inputString);
    TestScenarioAPI testScenario;

    if (m_ValidChecker.isValidCommand(inputString, testScriptTokens) == false) {
        if (m_ValidChecker.isValidScenario(inputString, testScenario) == false) {
            return Result_e::FAIL;
        }
        m_curCmd.type = "testcase";
        handleScenario(inputString, testScenario);
        *retCmd = m_curCmd;
        return Result_e::SUCCESS;
    }

    CommandType_e commandType = m_Parser.executeParse(testScriptTokens);
    m_curCmd = m_Parser.getParseResultCmd();

    if (commandType == CommandType_e::EXIT) {
        return Result_e::EXIT;
    }
    if (commandType == CommandType_e::HELP) {
        handleHelp();
    }
    *retCmd = m_curCmd;
    return Result_e::SUCCESS;
}

ShellCommand ShellCommandHandler::getCurrentCommand() {
    if (m_curCmd.type.empty()) {
        throw std::exception();
    }
    return m_curCmd;
}

IScenario* ShellCommandHandler::getCurrentScenario() {
    return m_pCurScenario;
}

void ShellCommandHandler::handleHelp() {
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

void ShellCommandHandler::handleScenario(const string& testScenario, TestScenarioAPI& scenarioLib) {
    // Call DLL to get the scenario class
    m_pCurScenario = scenarioLib.getScenario(testScenario);
}