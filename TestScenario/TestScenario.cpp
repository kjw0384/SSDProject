#include "TestScenario.h"
#include "../TestShellApp/IScenario.h"
#include <sstream>

class test1app : public IScenario {
public:
	test1app();
	void run() override;
private:
};
test1app::test1app() {
	vector<string> scenarios{
		"read 1 0x11111111",
		"write 7 0x22222222",
		"read 7"
	};

	for (const auto& scenario : scenarios) {
		Command cmd = parseCommand(scenario);
		m_TestScriptCommandVector.push_back(cmd);
	}
}
void test1app::run() {
	// 여기에 실행 로직을 추가하세요
	for (const auto& command : m_TestScriptCommandVector) {
		cout << "Type: " << command.type << ", LBA Index: " << command.LBAIndexNum << ", Value: " << command.value << endl;
	}
}

class test2app : public IScenario {
public:
	test2app();
	void run() override;
private:
};
test2app::test2app() {
	vector<string> scenarios{
		"read 3 0x33333333",
		"write 5 0x55555555",
		"read 5"
	};

	for (const auto& scenario : scenarios) {
		Command cmd = parseCommand(scenario);
		m_TestScriptCommandVector.push_back(cmd);
	}
}
void test2app::run() {
	for (const auto& command : m_TestScriptCommandVector) {
		cout << "Type: " << command.type << ", LBA Index: " << command.LBAIndexNum << ", Value: " << command.value << endl;
	}
}

IScenario* TestScenario::getScenario(const string& testScenario)
{
	IScenario* scenario{};
	if (testScenario == "testapp1")
		scenario = new test1app();
	else if (testScenario == "testapp2")
		scenario = new test2app();
	return scenario;
}

vector<string> TestScenario::getScenarios()
{
	vector<string> scenarios{ "testapp1", "testapp2" };
	return scenarios;
}