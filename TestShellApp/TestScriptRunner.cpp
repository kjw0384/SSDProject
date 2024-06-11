#include <iostream>
#include "TestScriptRunner.h"
#include "ResultFileReader.h"
#include "VirtualSsdProcess.h"
#include "../Project1/FileManager.h"
#include "Logger.h"


TestScriptRunner::TestScriptRunner()\
	: m_ssdProcessIf(new VirtaulSsdProcess), m_ReadResultIO(new ResultFileReader) {
}

TestScriptRunner::TestScriptRunner(VirtualSsdProcessInterface* pSsdProcInterface, ReadIOInterface* pReadIOInterface) 
	: m_ssdProcessIf(pSsdProcInterface), m_ReadResultIO(pReadIOInterface) {

}

Result_e TestScriptRunner::inputShellCmd(ShellCommand& cmd) {
	LOG_PRINT("type - " + cmd.type);
	if (cmd.type == "fullread") {
		cmd.type = "read";
		for (int lba = START_LBA; lba < END_LBA; ++lba) {
			cmd.LBAIndexNum = lba;
			m_ShellCmdVector.push_back(cmd);
		}
	}
	else if (cmd.type == "fullwrite") {
		cmd.type = "write";
		for (int lba = START_LBA; lba < END_LBA; ++lba) {
			cmd.LBAIndexNum = lba;
			m_ShellCmdVector.push_back(cmd);
		}
	}
	else {
		m_ShellCmdVector.push_back(cmd);
	}
	return Result_e::SUCCESS;
}

Result_e TestScriptRunner::run() {
	for (ShellCommand cmdVectIt : m_ShellCmdVector){
		if (callSsdProcess(cmdVectIt) == Result_e::FAIL)
		{
			LOG_PRINT(cmdVectIt.type + " Fail");
			return Result_e::FAIL;
		}
	}
	LOG_PRINT("run Success");
	return Result_e::SUCCESS;
}

Result_e TestScriptRunner::runTC() {
	for (ShellCommand cmdVectIt : m_ShellCmdVector) {
		if (callSsdProcessAndCompare(cmdVectIt) == Result_e::FAIL)
			return Result_e::FAIL;
	}
	return Result_e::SUCCESS;
}

void TestScriptRunner::setCmdVector(TestVector_t inputVector) {
	m_ShellCmdVector.clear();
	m_ShellCmdVector.reserve(inputVector.size());

	for (ShellCommand& cmd : inputVector) {
		if (cmd.type == "fullread") {
			cmd.type = "read";
			for (int lba = START_LBA; lba < END_LBA; ++lba) {
				cmd.LBAIndexNum = lba;
				m_ShellCmdVector.push_back(cmd);
			}
		}
		else if (cmd.type == "fullwrite") {
			cmd.type = "write";
			for (int lba = START_LBA; lba < END_LBA; ++lba) {
				cmd.LBAIndexNum = lba;
				m_ShellCmdVector.push_back(cmd);
			}
		}
		else {
			m_ShellCmdVector.push_back(cmd);
		}
	}
}

Result_e TestScriptRunner::callSsdProcessInternal(ShellCommand cmd) {
	LOG_PRINT(cmd.type);
	if (cmd.type == "write") {
		m_ssdProcessIf->sendWriteIpc(cmd.LBAIndexNum, cmd.value);
		return Result_e::SUCCESS;
	}
	else if (cmd.type == "erase") {
		int startLBA = cmd.LBAIndexNum;
		int remainSize = cmd.size;

		while (remainSize > 10) {
			m_ssdProcessIf->sendEraseIpc(startLBA, 10);
			startLBA += 10;
			remainSize -= 10;
		}
		m_ssdProcessIf->sendEraseIpc(startLBA, remainSize);

		return Result_e::SUCCESS;
	}
	else if (cmd.type == "flush") {
		m_ssdProcessIf->sendFlushIpc();
		return Result_e::SUCCESS;
	}
	return Result_e::FAIL;
}

Result_e TestScriptRunner::callSsdProcess(ShellCommand cmd) {
	if (cmd.type == "read") {
		m_ssdProcessIf->sendReadIpc(cmd.LBAIndexNum);
		string readResult = m_ReadResultIO->GetReadResult();

		std::cout << readResult << "\n";
		return Result_e::SUCCESS;
	}
	else {
		return callSsdProcessInternal(cmd);
	}
	return Result_e::FAIL;
}

Result_e TestScriptRunner::callSsdProcessAndCompare(ShellCommand cmd) {
	if (cmd.type == "read") {
		m_ssdProcessIf->sendReadIpc(cmd.LBAIndexNum);
		string readResult = m_ReadResultIO->GetReadResult();

		if (cmd.value != readResult)
			return Result_e::FAIL;
		return Result_e::SUCCESS;
	}
	else {
		return callSsdProcessInternal(cmd);
	}
	return Result_e::FAIL;
}