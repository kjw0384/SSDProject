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