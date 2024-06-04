#include <iostream>
#include <string>
#include <regex>

using namespace std;

class ShellStringParser {
public:
	const int ERROR_CMD_NOT_VALID = 1;
	const int ERROR_CMD_NOT_FOUND = 2;
	const int ERROR_CMD_ARGC_ERROR = 3;
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

			//Check Value
		}

		return 0;
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

