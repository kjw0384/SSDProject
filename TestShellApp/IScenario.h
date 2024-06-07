#pragma once
#include <iostream>
#include <sstream>
#include "TestCommand.h"

#define interface struct

using std::cout;

interface IScenario {
public:
	typedef vector<Command> TestVector_t;
	virtual ~IScenario() {}
	virtual void run() = 0;
	Command parseCommand(const string& scenario) {
		Command cmd;
		istringstream iss(scenario);
		string value;

		iss >> cmd.type >> cmd.LBAIndexNum;

		if (iss >> value) {
			cmd.value = value;
		}
		else {
			cmd.value = "";
		}

		return cmd;
	}

	void addCommand(const Command& cmd) {
		m_TestScriptCommandVector.push_back(cmd);
	}

	const TestVector_t& getCommands() const {
		return m_TestScriptCommandVector;
	}

	TestVector_t m_TestScriptCommandVector;
};
