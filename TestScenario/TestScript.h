#pragma once
#include <string>
#include <vector>

#include "../TestShellApp/IScenario.h"

using namespace std;

class TestScriptReadAndCompare : public  IScenario
{
public :
	TestScriptReadAndCompare(){
		m_name = "ReadAndCompare";
		vector<string> scenarios{
		"read 3 0x33333333",
		"write 5 0x55555555",
		"read 5",
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

class TestScriptTestApp1 : public  IScenario
{
public:
	TestScriptTestApp1() {
		vector<string> scenarios{
		"fullwrite 0x11223344",
		"fullread 0x11223344",
		};

		for (const auto& scenario : scenarios) {
			Command cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << "TestApp1\n";
	}
};

class TestScriptTestApp2 : public  IScenario
{
public:
	TestScriptTestApp2() {
		vector<string> scenarios{};
		const int numWrite = 30;
		const int startLBA = 0;
		const int endLBA = 5;
		string vector{};
		for (int i = 0; i < numWrite; ++i) {
			for (int k = startLBA; k <= endLBA; ++k) {
				vector = "write " + std::to_string(k) + " 0xAAAABBBB";
				scenarios.push_back(vector);
			}
		}
		for (int k = startLBA; k <= endLBA; ++k) {
			vector = "write " + std::to_string(k) + " 0x12345678";
			scenarios.push_back(vector);
		}
		for (int k = startLBA; k <= endLBA; ++k) {
			vector = "read " + std::to_string(k) + " 0x12345678";
			scenarios.push_back(vector);
		}

		for (const auto& scenario : scenarios) {
			Command cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << "TestApp2\n";
	}
};
