#pragma once

#include <string>
#include <vector>

#include "TestCommand.h"
#include "TestScriptValidChecker.h"
#include "TestShellCommon.h"

using std::string;
using std::vector;

class TestScriptParser
{
  public:
    vector<string> splitTestScript(const string &testScript);
    ShellCommand parseTestScript(vector<string> scriptTokens);
    CommandType_e getCommandType(ShellCmdType_t type);
    CommandType_e executeParse(vector<string> scriptTokens);
    ShellCommand getParseResultCmd();

  private:
    ShellCommand m_parsedCmd;
};
