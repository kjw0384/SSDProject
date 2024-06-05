#pragma once
#include <iostream>
#include <string>
#include <regex>

using namespace std;

enum class ShellStringParserError {
	NO_ERROR,
	CMD_EMPTY,
	CMD_NOT_FOUND,
	CMD_ARGC_ERROR,
	CMD_ARGV_ERROR
};


class ShellStringParser {
public:
	ShellStringParserError validCheck(vector<string> inputCmdVec);

private:
	bool isNotLBA(string strLBA);
	bool isNotValue(string strValue);
};

