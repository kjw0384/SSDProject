#include "TestScenario.h"
#include "TestScriptDataBase.h"
#include "../TestShellApp/IScenario.h"

//TODO: singleton
TestScriptDataBase g_TestCaseDB;

IScenario* TestScenario::getScenario(const string& testScenarioName) {
	return g_TestCaseDB.GetTestScriptCase(testScenarioName);
}

vector<string> TestScenario::getScenarios() {
	return g_TestCaseDB.getScenarioList();
}
//class test1app : public IScenario {
//public:
//	void run() override {
//		cout << "runScenario()\n";
//	}
//};
//
//class test2app : public IScenario {
//public:
//	void run() override {
//		cout << "runScenario()\n";
//	}
//};
//
//IScenario* TestScenario::getScenario(const string& testScenario)
//{
//	IScenario* scenario{};
//	if (testScenario == "testapp1")
//		scenario = new test1app();
//	else if (testScenario == "testapp2")
//		scenario = new test2app();
//	return scenario;
//}
//
//vector<string> TestScenario::getScenarios()
//{
//	vector<string> scenarios{ "testapp1", "testapp2" };
//	return scenarios;
//}

