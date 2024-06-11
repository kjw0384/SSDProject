#include "TestScriptValidChecker.h"
#include "Logger.h"
#include <algorithm>
#include <regex>
#include <vector>

using std::regex;
using std::vector;

bool TestScriptValidChecker::isValidScenario(string command, TestScenarioAPI &testScenario)
{
    vector<string> scenarios = testScenario.getScenarios();
    if (std::find(scenarios.begin(), scenarios.end(), command) != scenarios.end())
    {
        LOG_PRINT("Valid Scenarios");
        return true;
    }
    LOG_PRINT("Invalid Scenarios");
    return false;
}

bool TestScriptValidChecker::isValidCommand(string command, vector<string> testScriptTokens)
{
    if (isValidPattern(command) == false)
    {
        LOG_PRINT("Invalid Pattern");
        return false;
    }

    if (isValidErase(testScriptTokens) == false)
    {
        LOG_PRINT("Invalid Erase");
        return false;
    }

    LOG_PRINT("Valid Command");
    return true;
}

bool TestScriptValidChecker::isValidPattern(string command)
{
    vector<regex> patterns = {regex("^write +[0-9]{1,2} +0[xX][0-9a-fA-F]{8}$"),
                              regex("^read +[0-9]{1,2}$"),
                              regex("^exit$"),
                              regex("^help$"),
                              regex("^fullwrite +0[xX][0-9a-fA-F]{8}$"),
                              regex("^fullread$"),
                              regex("^erase +[0-9]{1,2} +[0-9]{1,3}$"),
                              regex("^erase_range +[0-9]{1,2} +[0-9]{1,3}$"),
                              regex("^flush$")};

    for (const auto &pattern : patterns)
    {
        if (std::regex_match(command, pattern))
        {
            return true;
        }
    }
    return false;
}

bool TestScriptValidChecker::isValidErase(vector<string> scriptTokens)
{
    ShellCmdType_t type = scriptTokens[0];

    if (type != "erase" && type != "erase_range")
        return true;

    int LBA = stoi(scriptTokens[1]);
    int size = stoi(scriptTokens[2]);

    if (type == "erase_range")
    {
        if (size > MAX_LBA)
            return false;
        size = size - LBA;
    }

    return isValidRange(LBA, size);
}

bool TestScriptValidChecker::isValidRange(Index_t LBA, Size_t size)
{
    if (size > MAX_LBA || size < MIN_LBA)
        return false;

    if (LBA + size > MAX_LBA)
        return false;

    return true;
}
