#pragma once
#include <string>

#include "../TestScenario/TestScenarioAPI.h"
#include "TestCommand.h"

using std::string;

class TestScriptValidChecker {
public:
	bool isValidScenario(string command, TestScenarioAPI& testScenario);
	bool isValidCommand(string command, vector<string> testScriptTokens);
	bool isValidPattern(string command);
	bool isValidErase(vector<string> scriptTokens);
	bool isValidRange(Index_t LBA, Size_t size);
};