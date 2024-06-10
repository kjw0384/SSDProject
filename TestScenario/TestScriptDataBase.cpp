#include "TestScriptDataBase.h"
#include "TestScriptFactory.h"
#include "../TestShellApp/IScenario.h"


TestScriptDataBase::TestScriptDataBase() {
	createTestScript("ReadAndCompare");
	createTestScript("testapp1");
	createTestScript("testapp2");
}

void TestScriptDataBase::createTestScript(string testScriptName) {
	m_TestScriptDB.push_back(TestScriptFactory::getInstance().createTestScript(testScriptName));
}

TestScriptDataBase& TestScriptDataBase::getInstance() {
	static TestScriptDataBase testScriptDBInsatnce;
	return testScriptDBInsatnce;
}

IScenario* TestScriptDataBase::GetTestScriptCase(string TestScriptName) {
	for (IScenario* testScriptCasetIter : m_TestScriptDB) {
		if (testScriptCasetIter->getName() == TestScriptName) {
			return testScriptCasetIter;
		}
	}
	return nullptr;
}

vector<string> TestScriptDataBase::getScenarioList() {
	vector<string> retStrVector;
	for (IScenario* testScriptCasetIter : m_TestScriptDB) {
		retStrVector.push_back(testScriptCasetIter->getName());
	}
	return retStrVector;
}

