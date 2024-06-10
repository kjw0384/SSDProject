#include "TestScenario.h"
#include "TestScriptDataBase.h"
#include "../TestShellApp/IScenario.h"

IScenario* TestScenario::getScenario(const string& testScenarioName) {
	return 	TestScriptDataBase::getInstance().GetTestScriptCase(testScenarioName);
}

vector<string> TestScenario::getScenarios() {
	return 	TestScriptDataBase::getInstance().getScenarioList();
}
