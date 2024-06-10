#include "ShellStringParser.h"


ShellStringParserError ShellStringParser::validCheck(vector<string> inputCmdVec) {

	if (inputCmdVec.empty())
		return ShellStringParserError::CMD_EMPTY;
	
	if (inputCmdVec[0] != "W" && inputCmdVec[0] != "w" &&
		inputCmdVec[0] != "R" && inputCmdVec[0] != "r" &&
		inputCmdVec[0] != "E" && inputCmdVec[0] != "e" &&
		inputCmdVec[0] != "F" && inputCmdVec[0] != "f")
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

	if (inputCmdVec[0] == "E" || inputCmdVec[0] == "e")
	{
		if (inputCmdVec.size() != 3)
			return ShellStringParserError::CMD_ARGC_ERROR;

		if (isNotLBA(inputCmdVec[1]))
			return ShellStringParserError::CMD_ARGV_ERROR;

		if (isNotSize(inputCmdVec[2]))
			return ShellStringParserError::CMD_ARGV_ERROR;

		if (isNotInRangeSize(inputCmdVec[1], inputCmdVec[2]))
			return ShellStringParserError::CMD_ARGV_ERROR;
	}

	if (inputCmdVec[0] == "F" || inputCmdVec[0] == "f")
	{
		if (inputCmdVec.size() != 1)
			return ShellStringParserError::CMD_ARGC_ERROR;
	}

	return ShellStringParserError::NO_ERROR;
}

bool ShellStringParser::isNotLBA(string strLBA) {
	regex txt_regex("^[0-9]+$");
	if (regex_match(strLBA, txt_regex) == false)
		return true;

	int nLBA = atoi(strLBA.c_str());
	if (nLBA < 0 || nLBA > 99)
		return true;

	return false;
}

bool ShellStringParser::isNotSize(string strSize) {
	regex txt_regex("^[0-9]{1,2}$");
	if (regex_match(strSize, txt_regex) == false)
		return true;

	int nSize = atoi(strSize.c_str());
	if (nSize < 0 || nSize > 10)
		return true;

	return false;
}

bool ShellStringParser::isNotInRangeSize(string strLBA, string strSize) {
	int nLBA= atoi(strLBA.c_str());
	int nSize = atoi(strSize.c_str());

	if (nLBA + nSize < 100) return false;
	return true;
}

bool ShellStringParser::isNotValue(string strValue) {
	regex txt_regex("^0[xX][0-9A-Fa-f]{8}$");
	if (regex_match(strValue, txt_regex) == false)
		return true;

	return false;
}
