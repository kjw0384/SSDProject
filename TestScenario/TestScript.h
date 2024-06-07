#pragma once
#include <string>
#include <vector>

struct Command {
	//TODO: sync to ShellCommand spec.
	std::string cmdName;
};

using namespace std;

class TestScript {
public:
	string getName() {
		return m_name;
	}

	void setName(string name) {
		m_name = name;
	}

	void InsertCommand(string CmdName) {
		Command cmd;
		cmd.cmdName = CmdName;
	}

	virtual void run() = 0;

private:
	string m_name;
	vector<Command> m_CmdVector;
};



#define TEST_SCRIPT_DESC_STRAT(NAME)\
class TestScript##NAME : public  TestScript\
{\
public :
#define TEST_SCRIPT_DESC_COMMAND(CMD)
#define TEST_SCRIPT_DESC_RUN(RUN_FUNC_IMPLE)\
	virtual void run()##RUN_FUNC_IMPLE##;
#define TEST_SCRIPT_DESC_END()\
};
#include "TestScriptDescriptor.h"