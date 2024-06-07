#pragma once
#include <iostream>
#include  <string>

#define interface struct

using std::cout;
using namespace std;

class IScenario {
public:
	string getName() {
		return m_name;
	}

	void setName(string name) {
		m_name = name;
	}

	void InsertCommand(string CmdName) {
		//Command cmd;
		//cmd.CmdName = CmdName;
	}

	virtual void run() = 0;

private:
	string m_name;
	//vector<Command> m_CmdVector;
};
