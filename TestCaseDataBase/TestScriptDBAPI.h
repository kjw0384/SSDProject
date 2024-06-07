#pragma once

#include "TestScript.h"
#include <string>

class TestScriptCaseDBAPI {
	static IScenario* GetTestCaseObj(std::string TcName);
};