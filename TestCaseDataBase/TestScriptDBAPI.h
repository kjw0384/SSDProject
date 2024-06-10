#pragma once

#include "TestScript.h"
#include <string>

class TestScriptCaseDBAPI {
	static TestScript* GetTestCaseObj(std::string TcName);
};