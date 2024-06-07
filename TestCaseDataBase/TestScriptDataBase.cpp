#include "TestScriptDataBase.h"
#include "TestScriptReadAndCompare.h" //todo: split to TestScript Factory

TestScriptDataBase::TestScriptDataBase() {
	TestScript* tscObj = nullptr;
#define TEST_SCRIPT_DESC_STRAT(NAME)\
			tscObj = new TestScript##NAME;\
			tscObj->setName( #NAME );
#define TEST_SCRIPT_DESC_COMMAND(COMMAND)\
			tscObj->InsertCommand( #COMMAND );
#define TEST_SCRIPT_DESC_END()
#include "TestScriptDescriptor.h"
}

TestScript* TestScriptDataBase::GetTestScriptCase(string TestScriptName) {
	for (TestScript* testScriptCasetIter : m_TestScriptDB) {
		if (testScriptCasetIter->getName() == TestScriptName) {
			return testScriptCasetIter;
		}
	}
	return nullptr;

}