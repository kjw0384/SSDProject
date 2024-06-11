#pragma once
#include <iostream>
#include <string>

#include <sstream>
#include <vector>
#include "TestCommand.h"

#define interface struct

using std::cout;
using namespace std;

interface IScenario {
public:
	typedef vector<Command> TestVector_t;

	virtual ~IScenario() {
	}

	virtual void run() = 0;

	string getName() {
		return m_name;
	}

	void setName(string name) {
		m_name = name;
	}

	const TestVector_t& getCommands() const {
		return m_TestScriptCommandVector;
	}

protected:
	void addCommand(const Command& cmd) {
		m_TestScriptCommandVector.push_back(cmd);

	}
	Command parseCommand(const string& scenario) {
		Command cmd;
		istringstream iss(scenario);
		string value;

		iss >> cmd.type;
		if((cmd.type!="fullwrite") && (cmd.type != "fullread"))
		iss >> cmd.LBAIndexNum;

		if (iss >> value) {
			cmd.value = value;
		}
		else {
			cmd.value = "";
		}

		return cmd;
	}

	string m_name;
	TestVector_t m_TestScriptCommandVector;
};

