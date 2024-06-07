#pragma once
#include "TestScript.h"
#include <vector>
#include <string>

using namespace std;

class TestScriptDataBase {
public:
	TestScriptDataBase();
	IScenario* GetTestScriptCase(string TestScriptName);
	vector<string> GetTestScriptlist() {
		return m_TestScriptNameVector;
	}
	
private:
	vector<IScenario*> m_TestScriptDB; //TODO: consider <string , TestCase> map container
	vector<string> m_TestScriptNameVector;
};