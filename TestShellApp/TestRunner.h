#pragma once

#include <vector>
#include <string>

#include "TestCommand.h" 

using namespace std;

class TestRunner {
public:
	void inputCmd(Command cmd) {
	}

	void run(Command cmd) {
	}

private:
	vector<Command> m_TestVector;
	//ssdApiBase* m_ApiBase;
};