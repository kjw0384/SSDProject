#include "TestScriptRunner.h"
#include <iostream>
#include "../Project1/FileManager.h"

TestScriptRunner::TestScriptRunner(VirtualSsdProcessInterface* pSsdProcIf, ReadIOInterface* pReadResultIO)\
	: m_ssdProcessIf(pSsdProcIf), m_ReadResultIO(pReadResultIO) {
}

Result_e TestScriptRunner::inputCmd(Command& cmd) {
	if (cmd.type == "fullread") {
		cmd.type = "read";
		for (int lba = START_LBA; lba < END_LBA; ++lba) {
			cmd.LBAIndexNum = lba;
			m_TestCommandVector.push_back(cmd);
		}
	}
	else if (cmd.type == "fullwrite") {
		cmd.type = "write";
		for (int lba = START_LBA; lba < END_LBA; ++lba) {
			cmd.LBAIndexNum = lba;
			m_TestCommandVector.push_back(cmd);
		}
	}
	else {
		m_TestCommandVector.push_back(cmd);
	}
	return Result_e::SUCCESS;
}

Result_e TestScriptRunner::run() {
	for (Command cmdVectIt : m_TestCommandVector){
		if (callSsdProcess(cmdVectIt) == Result_e::FAIL)
			return Result_e::FAIL;
	}
	return Result_e::SUCCESS;
}

Result_e TestScriptRunner::callSsdProcess(Command cmd) {
	if (cmd.type == "read") {
		m_ssdProcessIf->sendReadIpc(cmd.LBAIndexNum);
		string readResult = m_ReadResultIO->GetReadResult();
		std::cout << readResult << "\n";
		return Result_e::SUCCESS;
	}
	else if (cmd.type == "write") {
		m_ssdProcessIf->sendWriteIpc(cmd.LBAIndexNum, cmd.value);
		return Result_e::SUCCESS;
	}
	return Result_e::FAIL;
}

void TestScriptRunner::setvector(TestVector_t vector) {

	m_TestCommandVector = vector;
}