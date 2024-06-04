#include "TestRunner.h"

Result_e TestRunner::inputCmd(Command cmd) {
	m_TestVector.push_back(cmd);
	return SUCCESS;
}

Result_e TestRunner::run() {
	for (TestVector_t::iterator vectIt = m_TestVector.begin(); vectIt != m_TestVector.end(); ++vectIt) {
		if (callSsdApi(*vectIt) == FAIL) return FAIL;
	}
	return SUCCESS;
}

Result_e TestRunner::callSsdApi(Command cmd) {
	if (cmd.type == "READ") {
		// place read API
		return SUCCESS;
	}
	else if (cmd.type == "WRITE") {
		// place write API
		return SUCCESS;
	}
	return FAIL;
}
