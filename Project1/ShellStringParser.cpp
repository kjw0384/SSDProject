#include "ShellStringParser.h"


ShellStringParserError ShellStringParser::validCheck(vector<string> inputCmdVec) {
	// Error
	if (inputCmdVec.empty())
		return ShellStringParserError::CMD_EMPTY;

	if (inputCmdVec[0] != "W" && inputCmdVec[0] != "R")
	{
		return ShellStringParserError::CMD_NOT_FOUND;
	}

	if (inputCmdVec[0] == "W")
	{
		if (inputCmdVec.size() != 3)
			return ShellStringParserError::CMD_ARGC_ERROR;

		if (isNotLBA(inputCmdVec[1]))
			return ShellStringParserError::CMD_ARGV_ERROR;

		if (isNotValue(inputCmdVec[2]))
			return ShellStringParserError::CMD_ARGV_ERROR;
	}
	if (inputCmdVec[0] == "R")
	{
		if (inputCmdVec.size() != 2)
			return ShellStringParserError::CMD_ARGC_ERROR;

		if (isNotLBA(inputCmdVec[1]))
			return ShellStringParserError::CMD_ARGV_ERROR;

	}

	return ShellStringParserError::NO_ERROR;
}

bool ShellStringParser::isNotLBA(string strLBA) {
	regex txt_regex("^[0-9]+$");
	if (regex_match(strLBA, txt_regex) == false)
		return true;

	int nLBA = atoi(strLBA.c_str());
	if (nLBA < 0 || nLBA > 100)
		return true;

	return false;
}

bool ShellStringParser::isNotValue(string strValue) {
	regex txt_regex("^0x[0-9A-F]{8}$");
	if (regex_match(strValue, txt_regex) == false)
		return true;

	return false;
}
