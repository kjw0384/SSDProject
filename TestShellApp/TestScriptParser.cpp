#include "TestScriptParser.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

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

Result_e TestScriptParser::executeParse(vector<string> arguments) {

    string testScript="";
    for (int i = 0; i < arguments.size(); ++i) {
        testScript += arguments[i];
        testScript += " ";
        if (i == arguments.size() - 1) testScript.pop_back();
    }

    if (checker.isValidCommand(testScript) == false) {
        return Result_e::FAIL;
    }

    testCmd = parseTestScript(arguments);

    return Result_e::SUCCESS;
}

Command TestScriptParser::getTestCmd() {
    return testCmd;
}
