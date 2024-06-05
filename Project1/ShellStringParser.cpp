#include "ShellStringParser.h"


ShellStringParserError ShellStringParser::validCheck(vector<string> inputCmdVec) {

	if (inputCmdVec.empty())
		return ShellStringParserError::CMD_EMPTY;
	
	if (inputCmdVec[0] != "W" && inputCmdVec[0] != "w" &&
		inputCmdVec[0] != "R" && inputCmdVec[0] != "r")
	{
		return ShellStringParserError::CMD_NOT_FOUND;
	}

	if (inputCmdVec[0] == "W" || inputCmdVec[0] == "w")
	{
		if (inputCmdVec.size() != 3)
			return ShellStringParserError::CMD_ARGC_ERROR;

		if (isNotLBA(inputCmdVec[1]))
			return ShellStringParserError::CMD_ARGV_ERROR;

		if (isNotValue(inputCmdVec[2]))
			return ShellStringParserError::CMD_ARGV_ERROR;
	}

	if (inputCmdVec[0] == "R" || inputCmdVec[0] == "r")
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
	regex txt_regex("^0[xX][0-9A-Fa-f]{8}$");
	if (regex_match(strValue, txt_regex) == false)
		return true;

	return false;
}
