#include "TestScenarioAPI.h"
#include "../TestShellApp/IScenario.h"

class test1app : public IScenario {
public:
	void run() override {
		cout << "runScenario()\n";
	}
};

class test2app : public IScenario {
public:
	void run() override {
		cout << "runScenario()\n";
	}
};

IScenario* TestScenarioAPI::getScenario(const string& testScenario)
{
	IScenario* scenario{};
	if (testScenario == "testapp1")
		scenario = new test1app();
	else if (testScenario == "testapp2")
		scenario = new test2app();
	return scenario;
}

vector<string> TestScenarioAPI::getScenarios()
{
	vector<string> scenarios{ "testapp1", "testapp2" };
	return scenarios;
}