#include <regex>
#include <vector>
#include <algorithm>
#include "TestScriptValidChecker.h"
#include "../TestScenario/TestScenario.h"

using std::vector;
using std::string;
using std::regex;

bool TestScriptValidChecker::isValidCommand(string command) {
	vector<regex> patterns = {
		regex("^write +[0-9]{1,2} +0[xX][0-9a-fA-F]{8}$"),
		regex("^read +[0-9]{1,2}$"),
		regex("^exit$"),
		regex("^help$"),
		regex("^fullwrite +0[xX][0-9a-fA-F]{8}$"),
		regex("^fullread$")
	};

	for (const auto& pattern : patterns) {
		if (std::regex_match(command, pattern)) {
			return true;
		}
	}
	return false;
}

bool TestScriptValidChecker::isValidScenario(string command, TestScenario& testScenario) {
	vector<string> scenarios = testScenario.getScenarios();
	if (auto it = std::find(scenarios.begin(), scenarios.end(), command);
		it != scenarios.end())
		return true;
	return false;
}