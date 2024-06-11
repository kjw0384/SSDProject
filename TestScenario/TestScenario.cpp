#include "../TestShellApp/IScenario.h"
#include "TestScenarioAPI.h"
#include "TestScriptDataBase.h"

IScenario *TestScenarioAPI::getScenario(const string &testScenarioName)
{
    return TestScriptDataBase::getInstance().GetTestScriptCase(testScenarioName);
}

vector<string> TestScenarioAPI::getScenarios()
{
    return TestScriptDataBase::getInstance().getScenarioList();
}
