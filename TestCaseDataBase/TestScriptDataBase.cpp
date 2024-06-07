﻿#include "TestScriptDataBase.h"
#include "TestScript.h" //todo: split to TestScript Factory

TestScriptDataBase::TestScriptDataBase() {
	IScenario* tscObj = nullptr;
#define TEST_SCRIPT_DESC_STRAT(NAME)\
			tscObj = new IScenario##NAME;\
			tscObj->setName( #NAME );
#define TEST_SCRIPT_DESC_COMMAND(COMMAND)\
			tscObj->InsertCommand( #COMMAND );
#define TEST_SCRIPT_DESC_RUN(RUN_IMPLE)
#define TEST_SCRIPT_DESC_END()\
			m_TestScriptDB.push_back(tscObj);
#include "TestScriptDescriptor.h"
}

IScenario* TestScriptDataBase::GetTestScriptCase(string TestScriptName) {
	for (IScenario* testScriptCasetIter : m_TestScriptDB) {
		if (testScriptCasetIter->getName() == TestScriptName) {
			return testScriptCasetIter;
		}
	}
	return nullptr;

}