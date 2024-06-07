#pragma once
#include <string>
#include "../TestScenario/TestScenario.h"

using std::string;

class TestScriptValidChecker {
public:
	bool isValidCommand(string command);
	bool isValidScenario(string command, TestScenario& testScenario);
};