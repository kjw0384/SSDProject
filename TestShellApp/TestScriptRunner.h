#pragma once

#include <vector>
#include <string>

#include "TestCommand.h"
#include "TestShellCommon.h"
#include "ReadIOInterface.h" //TODO: sync to readio
#include "VirtualSsdProcessInterface.h"

using namespace std;

class TestScriptRunner {
public:
	typedef vector<Command> TestVector_t;

	explicit TestScriptRunner(VirtualSsdProcessInterface* pSsdProcIf, ReadIOInterface* pReadResultIO);
	Result_e inputCmd(Command& cmd);
	Result_e run();
	Result_e runTC();

	void setvector(TestVector_t vector);
private:
	Result_e callSsdProcess(Command cmd);
	Result_e callSsdProcessAndCompare(Command cmd);

	TestVector_t m_TestCommandVector;
	VirtualSsdProcessInterface* m_ssdProcessIf;
	ReadIOInterface* m_ReadResultIO;
};


