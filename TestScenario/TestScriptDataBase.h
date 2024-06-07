#pragma once
#include "TestScript.h"
#include <vector>
#include <string>

using namespace std;

class TestScriptDataBase {
public:
	TestScriptDataBase();
	TestScript* GetTestScriptCase(string TestScriptName);

	vector<TestScript*> m_TestScriptDB; //TODO: consider <string , TestCase> map container
};