#include "../TestShellApp/IScenario.h"
#include <string>

using namespace std;

class TestScriptFactory {
public:
	static TestScriptFactory& getInstance();
	IScenario* createTestScript(string scriptName);
private:
};