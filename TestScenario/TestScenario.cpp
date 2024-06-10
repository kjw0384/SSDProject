#include "TestScenario.h"
#include "TestScriptDataBase.h"
#include "../TestShellApp/IScenario.h"

//TODO: singleton
TestScriptDataBase g_TestCaseDB;

IScenario* TestScenario::getScenario(const string& testScenarioName) {
	return g_TestCaseDB.GetTestScriptCase(testScenarioName);
}

vector<string> TestScenario::getScenarios() {
	return g_TestCaseDB.getScenarioList();
}

