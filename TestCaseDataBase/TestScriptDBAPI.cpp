#include "TestScriptDBAPI.h"
#include "TestScriptDataBase.h"

//TODO: singleton
TestScriptDataBase g_TestCaseDB;

IScenario* TestScriptCaseDBAPI::GetTestCaseObj(std::string TcName) {
	return g_TestCaseDB.GetTestScriptCase(TcName);
}
