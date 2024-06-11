#include "TestScenarioAPI.h"
#include "TestScriptDataBase.h"
#include "../TestShellApp/IScenario.h"

IScenario* TestScenarioAPI::getScenario(const string& testScenarioName) {
	return 	TestScriptDataBase::getInstance().GetTestScriptCase(testScenarioName);
}

vector<string> TestScenarioAPI::getScenarios() {
	return 	TestScriptDataBase::getInstance().getScenarioList();
}
