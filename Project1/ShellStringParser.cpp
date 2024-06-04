#include <iostream>
#include <string>
#include <regex>

using namespace std;

class ShellStringParser {
public:
	const int ERROR_CMD_NOT_VALID = 1;
	const int ERROR_CMD_NOT_FOUND = 2;
	const int ERROR_CMD_ARGC_ERROR = 3;
	const int ERROR_CMD_ARGV_ERROR = 4;

	int validCheck(string inputCmd) {
		// Error
		if (inputCmd == "")
			return ERROR_CMD_NOT_VALID;
		
		vector<string> cmdVec = split(inputCmd);
		if (cmdVec[0] != "W" && cmdVec[0] != "R")
		{
			return ERROR_CMD_NOT_FOUND;
		}
		if (cmdVec[0] == "W")
		{
			//Check Size
			if (cmdVec.size() != 3)
				return ERROR_CMD_ARGC_ERROR;

			//Check LBA
			if (isNotLBA(cmdVec[1]))
				return ERROR_CMD_ARGV_ERROR;

			//Check Value
			if (isNotValue(cmdVec[2]))
				return ERROR_CMD_ARGV_ERROR;
		}

		return 0;
	}

	bool isNotLBA(string strLBA) {
		regex txt_regex("^[0-9]+$");
		if (regex_match(strLBA, txt_regex) == false)
			return true;

		int nLBA = atoi(strLBA.c_str());
		if (nLBA < 0 || nLBA > 100)
			return true;

		return false;
	}

	bool isNotValue(string strValue) {
		regex txt_regex("^0x[0-9A-F]{8}$");
		if (regex_match(strValue, txt_regex) == false)
			return true;

		return false;
	}
	
	vector<string> split(string inputCmd) {
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
};

