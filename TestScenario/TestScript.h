#pragma once
#include <string>
#include <vector>

#include "../TestShellApp/IScenario.h"

using namespace std;

class TestScriptReadAndCompare : public  IScenario
{
public :
	TestScriptReadAndCompare(){
		vector<string> scenarios{
		"read 3 0x00000000",
		"write 5 0x55555555",
		"read 5 0x55555555",
		};

		for (const auto& scenario : scenarios) {
			Command cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << "ReadAndCompare\n";
	}
};