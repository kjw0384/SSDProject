#pragma once
#include <iostream>
#include <string>

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
		m_CmdVector.push_back(CmdName);
	}

	virtual void run() = 0;

private:
	string m_name;
	vector<string> m_CmdVector;
};
