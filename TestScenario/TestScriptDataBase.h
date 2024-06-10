#pragma once

#include "TestScript.h"
#include <vector>
#include <string>

using namespace std;

class TestScriptDataBase {
public:
	TestScriptDataBase();
	IScenario* GetTestScriptCase(string TestScriptName);

	vector<string> getScenarioList();
private:
	vector<IScenario*> m_TestScriptDB; //TODO: consider <string , TestCase> map container
};