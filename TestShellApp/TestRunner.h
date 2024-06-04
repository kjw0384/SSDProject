#pragma once

#include <vector>
#include <string>

#include "TestCommand.h" 
#include "TestShellCommon.h" 

using namespace std;

class TestRunner {
public:
	typedef vector<Command> TestVector_t;

	Result_e inputCmd(Command cmd);

	Result_e run();

private:
	Result_e callSsdApi(Command cmd);

	TestVector_t m_TestVector;
	//ssdApiBase* m_ApiBase;
};