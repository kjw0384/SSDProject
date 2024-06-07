#include "TestScenarioAPI.h"
#include "../TestShellApp/IScenario.h"
#include "TestScriptDataBase.h"

TestScriptDataBase g_TestCaseDB;

IScenario* TestScenarioAPI::getScenario(const string& TestScenarioName)
{
	return g_TestCaseDB.GetTestScriptCase(TestScenarioName);
}

vector<string> TestScenarioAPI::getScenarios() {
	return g_TestCaseDB.GetTestScriptlist();
}