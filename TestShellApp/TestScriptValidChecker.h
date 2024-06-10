#pragma once
#include <string>

#include "../TestScenario/TestScenario.h"
#include "TestCommand.h"

using std::string;

class TestScriptValidChecker {
public:
	bool isValidScenario(string command, TestScenario& testScenario);
	bool isValidCommand(string command, vector<string> testScriptTokens);
	bool isValidPattern(string command);
	bool isValidErase(vector<string> scriptTokens);
	bool isValidRange(Index_t LBA, Size_t size);
};