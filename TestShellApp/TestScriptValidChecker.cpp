#include "TestScriptValidChecker.h"
#include <regex>
#include <vector>

using std::vector;
using std::string;
using std::regex;

bool TestScriptValidChecker::isValidCommand(string command) {
	vector<regex> patterns = {
		regex("^write +[0-9]+ +0x[0-9a-fA-F]{8}$"),
		regex("^read +[0-9]$"),
		regex("^exit$"),
		regex("^help$"),
		regex("^fullwrite$"),
		regex("^fullread$")
	};

	for (const auto& pattern : patterns) {
		if (std::regex_match(command, pattern)) {
			return true;
		}
	}
	return false;
}