#include "TestScript.h"
#include <vector>
#include <string>

using namespace std;

class TestScriptDataBase {
public:
	TestScriptDataBase();
	IScenario* GetTestScriptCase(string TestScriptName);
	vector<IScenario*> GetAllTestScript() {
		return m_TestScriptDB;
	}


private:
	vector<IScenario*> m_TestScriptDB; //TODO: consider <string , TestCase> map container
};