#pragma once

#include <vector>
#include <string>

#include "TestCommand.h"
#include "TestShellCommon.h"
#include "ReadIOinterface.h" //TODO: sync to readio
#include "VirtualSsdProcessInterface.h"

using namespace std;

class TestScriptRunner {
public:
	typedef vector<Command> TestVector_t;

	explicit TestScriptRunner(VirtualSsdProcessInterface* pSsdProcIf, ReadIOInterface* pReadResultIO);
	Result_e inputCmd(Command& cmd);
	Result_e run();

private:
	Result_e callSsdProcess(Command cmd);

	TestVector_t m_TestCommandVector;
	VirtualSsdProcessInterface* m_ssdProcessIf;
	ReadIOInterface* m_ReadResultIO;
};


