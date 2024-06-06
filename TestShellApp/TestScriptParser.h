#pragma once

#include <string>
#include <vector>

#include "TestCommand.h"
#include "TestShellCommon.h"
#include "TestScriptValidChecker.h"

using std::string;
using std::vector;

class TestScriptParser {
public:
    vector<string> splitTestScript(const string& testScript);
    Command parseTestScript(vector<string> scriptTokens);
    CommandType_e getCommandType(cmdType_t type);
    CommandType_e executeParse(const string& testScript);
    Command getTestCmd();

private:
    Command testCmd;
    TestScriptValidChecker checker;
};