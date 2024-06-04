#include "ShellStringParser.h"


ShellStringParserError ShellStringParser::validCheck(string inputCmd) {
	// Error
	if (inputCmd == "")
		return ShellStringParserError::CMD_EMPTY;

	vector<string> cmdVec = split(inputCmd);
	if (cmdVec[0] != "W" && cmdVec[0] != "R")
	{
		return ShellStringParserError::CMD_NOT_FOUND;
	}
	if (cmdVec[0] == "W")
	{
		if (cmdVec.size() != 3)
			return ShellStringParserError::CMD_ARGC_ERROR;

		if (isNotLBA(cmdVec[1]))
			return ShellStringParserError::CMD_ARGV_ERROR;

		if (isNotValue(cmdVec[2]))
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

vector<string> ShellStringParser::split(string inputCmd) {
	vector<string> cmdVector;
	int nPrevPos = 0;
	int nNextPos = inputCmd.find(" ");
	string str = "";
	while (nNextPos != string::npos) {
		str = inputCmd.substr(nPrevPos, nNextPos - nPrevPos);
		if (str != "")
			cmdVector.push_back(str);
		nPrevPos = nNextPos + 1;
		nNextPos = inputCmd.find(" ", nNextPos + 1);
	}
	str = inputCmd.substr(nPrevPos, nNextPos - nPrevPos);
	if (str != "")
		cmdVector.push_back(str);

	return cmdVector;
}
