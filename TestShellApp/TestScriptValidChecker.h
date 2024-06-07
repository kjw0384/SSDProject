#pragma once
#include <string>

using std::string;

class TestScriptValidChecker {
public:
	bool isValidCommand(string command);
	bool isValidScenario(string command);
};