#include "TestScriptRunner.h"


TestScriptRunner::TestScriptRunner(VirtualSsdProcessInterface* pSsdProcIf, ReadIOInterface* pReadResultIO)\
	: m_ssdProcessIf(pSsdProcIf), m_ReadResultIO(pReadResultIO) {
}

Result_e TestScriptRunner::inputCmd(Command cmd) {
	m_TestCommandVector.push_back(cmd);
	return Result_e::SUCCESS;
}

Result_e TestScriptRunner::run() {
	for (Command cmdVectIt : m_TestCommandVector){
		if (callSsdProcess(cmdVectIt) == Result_e::FAIL) return Result_e::FAIL;
	}
	return Result_e::SUCCESS;
}

Result_e TestScriptRunner::callSsdProcess(Command cmd) {
	if (cmd.type == "READ") {
		m_ssdProcessIf->sendReadIpc(getLBAAddr(cmd.LBAIndexNum));
		string readResult = m_ReadResultIO->GetReadResult();
		if (readResult != cmd.value) return Result_e::FAIL;
		return Result_e::SUCCESS;
	}
	else if (cmd.type == "WRITE") {
		m_ssdProcessIf->sendWriteIpc(getLBAAddr(cmd.LBAIndexNum), cmd.value);
		return Result_e::SUCCESS;
	}
	return Result_e::FAIL;
}

int TestScriptRunner::getLBAAddr(int LBAIndex) {
	return 0x0; // place LBA address translation
}