#include "TestRunner.h"

Result_e TestRunner::inputCmd(Command cmd) {
	m_TestCommandVector.push_back(cmd);
	return Result_e::SUCCESS;
}

Result_e TestRunner::run() {
	//for (TestVector_t::iterator vectIt = m_TestVector.begin(); vectIt != m_TestVector.end(); ++vectIt) {
	for (Command cmdVectIt : m_TestCommandVector){
		if (callSsdApi(cmdVectIt) == Result_e::FAIL) return Result_e::FAIL;
	}
	return Result_e::SUCCESS;
}

Result_e TestRunner::callSsdApi(Command cmd) {
	if (cmd.type == "READ") {
		// place read API
		return Result_e::SUCCESS;
	}
	else if (cmd.type == "WRITE") {
		// place write API
		return Result_e::SUCCESS;
	}
	return Result_e::FAIL;
}
