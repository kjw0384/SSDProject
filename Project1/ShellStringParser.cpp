#include <string>

using namespace std;

class ShellStringParser {
public:
	const int ERROR_CMD_NOT_VALID = 1;
	int validCheck(string s) {
		if (s == "")
			return ERROR_CMD_NOT_VALID;
		return 0;
	}
};

