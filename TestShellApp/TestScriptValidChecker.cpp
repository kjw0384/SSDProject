#include <regex>
#include <vector>
#include <algorithm>
#include "TestScriptValidChecker.h"
#include "../TestScenario/TestScenario.h"

using std::vector;
using std::regex;

bool TestScriptValidChecker::isValidScenario(string command, TestScenario& testScenario) {
	vector<string> scenarios = testScenario.getScenarios();
	if (std::find(scenarios.begin(), scenarios.end(), command) != scenarios.end())
		return true;
	return false;
}

bool TestScriptValidChecker::isValidCommand(string command, vector<string> testScriptTokens) {
	if (isValidPattern(command) == false) {
		return false;
	}

	if (isValidErase(testScriptTokens) == false) {
		return false;
	}

	return true;
}

bool TestScriptValidChecker::isValidPattern(string command) {
	vector<regex> patterns = {
		regex("^write +[0-9]{1,2} +0[xX][0-9a-fA-F]{8}$"),
		regex("^read +[0-9]{1,2}$"),
		regex("^exit$"),
		regex("^help$"),
		regex("^fullwrite +0[xX][0-9a-fA-F]{8}$"),
		regex("^fullread$"),
		regex("^erase +[0-9]{1,2} +[0-9]{1,3}$"),
		regex("^erase_range +[0-9]{1,2} +[0-9]{1,3}$"),
		regex("^flush$")
	};

	for (const auto& pattern : patterns) {
		if (std::regex_match(command, pattern)) {
			return true;
		}
	}
	return false;
}

bool TestScriptValidChecker::isValidErase(vector<string> scriptTokens) {
	cmdType_t type = scriptTokens[0];
	if (type == "erase") {
		int LBA = stoi(scriptTokens[1]);
		int size = stoi(scriptTokens[2]);
		if (isValidSize(LBA, size) == false) {
			return false;
		}
	}

	if (type == "erase_range") {
		int startLBA = stoi(scriptTokens[1]);
		int endLBA = stoi(scriptTokens[2]);
		if (isValidRange(startLBA, endLBA) == false) {
			return false;
		}
	}
	return true;
}

bool TestScriptValidChecker::isValidSize(Index_t LBA, Size_t size) {
	if (size > MAX_LBA)
		return false;

	if (LBA + size > MAX_LBA)
		return false;

	return true;
}

bool TestScriptValidChecker::isValidRange(Index_t startLBA, Index_t endLBA) {
	if (endLBA <= startLBA)
		return false;

	return isValidSize(startLBA, endLBA - startLBA);
}