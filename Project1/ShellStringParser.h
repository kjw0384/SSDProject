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
	bool isNotLBA(string strLBA);
	bool isNotSize(string strSize);
	bool isNotInRangeSize(string strLBA, string strSize);
	bool isNotValue(string strValue);
};

