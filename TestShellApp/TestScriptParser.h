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
   
    Command parseTestScript(vector<string> scriptTokens);
    Result_e executeParse(vector<string> arguments);
    Command getTestCmd();

private:
    Command testCmd;
    TestScriptValidChecker checker;
};