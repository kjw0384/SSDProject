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
		"write 5 0x55555555",
		"read 5 0x55555555",
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
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
		m_name = "testapp1";
		vector<string> scenarios{
		"fullwrite 0x11223344",
		"fullread 0x11223344",
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
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
		m_name = "testapp2";
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
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << "TestApp2\n";
	}
};

class TestScriptReadFailCase : public  IScenario
{
public:
	TestScriptReadFailCase() {
		m_name = "ReadFailCase";
		vector<string> scenarios{
		"write 5 0x55555555",
		"read 5 0x11111111",
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << "ReadFailCase\n";
	}
};

class TestScriptReadWrite : public  IScenario
{
public:
	TestScriptReadWrite() {
		m_name = "ReadWrite";
		vector<string> scenarios{
		"write 1 " + m_value,
		"read 1 " + m_value,
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << m_name;
	}
protected:
	string m_value{ "0xFFFFFFFF" };
};

class TestScriptPatternMSB : public  IScenario
{
public:
	TestScriptPatternMSB() {
		m_name = "PatternMSB";
		vector<string> scenarios{
		"write 1 " + m_value,
		"read 1 " + m_value,
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << m_name;
	}
private:
	string m_value{ "0x80000000" };
};

class TestScriptPatternLSB : public  IScenario
{
public:
	TestScriptPatternLSB() {
		m_name = "PatternLSB";
		vector<string> scenarios{
		"write 1 " + m_value,
		"read 1 " + m_value,
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << m_name;
	}
private:
	string m_value{ "0x00000001" };
};


class TestScriptPattern0xFFFFFFFF : public  IScenario
{
public:
	TestScriptPattern0xFFFFFFFF() {
		m_name = "Pattern0xFFFFFFFF";
		vector<string> scenarios{
		"write 1 " + m_value,
		"read 1 " + m_value,
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << m_name;
	}
private:
	string m_value{ "0xFFFFFFFF" };
};

class TestScriptPattern0x5A5A5A5A : public  IScenario
{
public:
	TestScriptPattern0x5A5A5A5A() {
		m_name = "Pattern0x5A5A5A5A";
		vector<string> scenarios{
		"write 1 " + m_value,
		"read 1 " + m_value,
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << m_name;
	}
private:
	string m_value{ "0x5A5A5A5A" };
};

class TestScriptPattern0xA5A5A5A5 : public  IScenario
{
public:
	TestScriptPattern0xA5A5A5A5() {
		m_name = "Pattern0xA5A5A5A5";
		vector<string> scenarios{
		"write 1 " + m_value,
		"read 1 " + m_value,
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << m_name;
	}
private:
	string m_value{ "0xA5A5A5A5" };
};

class TestScriptOneBit : public  IScenario
{
public:
	TestScriptOneBit() {
		m_name = "OneBit";
		vector<string> scenarios{
		"write 1 " + m_value,
		"read 1 " + m_value,
		};

		for (const auto& scenario : scenarios) {
			ShellCommand cmd = parseCommand(scenario);
			m_TestScriptCommandVector.push_back(cmd);
		}
	}
	virtual void run() {
		cout << m_name;
	}
private:
	string m_value{ "0x00010000" };
};