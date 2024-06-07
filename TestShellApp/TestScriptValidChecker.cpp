#include "TestScriptValidChecker.h"
#include <regex>
#include <vector>
#include <algorithm>

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

bool TestScriptValidChecker::isValidScenario(string command) {
	// Call DLL to get all the valid scenario names
	//vector<string> scenarios = getScenarios();
	vector<string> scenarios{ "testapp1", "testapp2" };
	if (auto it = std::find(scenarios.begin(), scenarios.end(), command);
		it != scenarios.end())
		return true;
	return false;
}