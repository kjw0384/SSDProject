#include <iostream>
#include <string>

using namespace std;

class ShellStringParser {
public:
	const int ERROR_CMD_NOT_VALID = 1;
	int validCheck(string inputCmd) {
		if (inputCmd == "")
			return ERROR_CMD_NOT_VALID;

		return 0;
	}
};

