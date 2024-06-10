#include "TestScriptDataBase.h"
#include "TestScript.h" //todo: split to TestScript Factory
#include "../TestShellApp/IScenario.h"


TestScriptDataBase::TestScriptDataBase() {
	IScenario* tscObj = nullptr;
	tscObj = new TestScriptReadAndCompare;
	tscObj->setName("ReadAndCompare");
	m_TestScriptDB.push_back(tscObj);

	tscObj = new TestScriptTestApp1;
	tscObj->setName("testapp1");
	m_TestScriptDB.push_back(tscObj);

	tscObj = new TestScriptTestApp2;
	tscObj->setName("testapp2");
	m_TestScriptDB.push_back(tscObj);
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

