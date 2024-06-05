#pragma once

#include <vector>
#include <string>

#include "TestCommand.h"
#include "TestShellCommon.h"
#include "ReadIOinterface.h" //TODO: sync to readio
#include "VirtualSsdProcessInterface.h"

using namespace std;

class TestRunner {
public:
	explicit TestRunner(VirtualSsdProcessInterface* pSsdProcIf, ReadIOInterface* pReadResultIO);
	typedef vector<Command> TestVector_t;

	Result_e inputCmd(Command cmd);
	Result_e run();

private:
	Result_e callSsdProcess(Command cmd);
	int getLBAAddr(int LBAIndex);

	TestVector_t m_TestCommandVector;
	VirtualSsdProcessInterface* m_ssdProcessIf;
	ReadIOInterface* m_ReadResultIO;
};


