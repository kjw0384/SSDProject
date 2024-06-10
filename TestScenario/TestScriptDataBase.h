#pragma once

#include "TestScript.h"
#include <vector>
#include <string>

using namespace std;

class TestScriptDataBase {
public:
	IScenario* GetTestScriptCase(string TestScriptName);

	vector<string> getScenarioList();

	static TestScriptDataBase& getInstance();
private:
	TestScriptDataBase();
	vector<IScenario*> m_TestScriptDB;
};