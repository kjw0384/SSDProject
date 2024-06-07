#pragma once
#include <string>
#include "../TestScenario/TestScenarioAPI.h"

using std::string;

class TestScriptValidChecker {
public:
	bool isValidCommand(string command);
	bool isValidScenario(string command, TestScenarioAPI& testScenario);
};