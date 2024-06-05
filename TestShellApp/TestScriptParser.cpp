#include "TestScriptParser.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

vector<string> TestScriptParser::splitTestScript(const string & testScript) {
    vector<string> scriptTokens;
    std::istringstream ss(testScript);
    string token;

    while (ss >> token) {
        scriptTokens.push_back(token);
    }
    return scriptTokens;
}

Command TestScriptParser::parseTestScript(vector<string> scriptTokens) {
    Command cmd;
    if (scriptTokens.size() > 0) {
        cmd.type = scriptTokens[0];
    }
    if (scriptTokens.size() > 1) {
        cmd.LBAIndexNum = std::stoi(scriptTokens[1]);
    }
    if (scriptTokens.size() > 2) {
        cmd.value = scriptTokens[2];
    }
    return cmd;
}

Result_e TestScriptParser::executeParse(const string& testScript) {

    if (checker.isValidCommand(testScript) == false) {
        return Result_e::FAIL;
    }

    vector<string> scriptTokens = splitTestScript((testScript));
    testCmd = parseTestScript(scriptTokens);

    return Result_e::SUCCESS;
}

Command TestScriptParser::getTestCmd() {
    if (testCmd.type.empty()) {
        throw std::exception();
    }
    return testCmd;
}
