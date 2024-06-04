#include "TestRunner.h"

Result_e TestRunner::inputCmd(Command cmd) {
	m_TestVector.push_back(cmd);
	return FAIL;
}

Result_e TestRunner::run() {
	for (TestVector_t::iterator vectIt = m_TestVector.begin(); vectIt != m_TestVector.end(); ++vectIt) {
		callSsdApi(*vectIt);
	}
	return FAIL;
}

Result_e TestRunner::callSsdApi(Command cmd) {
	if (cmd.type == "READ") {
		// place read API
	}
	else if (cmd.type == "WRITE") {
		// place write API
	}
	return FAIL; 
}
