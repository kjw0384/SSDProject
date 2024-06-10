#include "TestScriptFactory.h"
#include "TestScript.h"
#include <string>

TestScriptFactory& TestScriptFactory::getInstance() {
	static TestScriptFactory testScriptFactoryInstance;
	return testScriptFactoryInstance;
}

IScenario* TestScriptFactory::createTestScript(string scriptName) {
	if (scriptName == "ReadAndCompare") {
		return new TestScriptReadAndCompare;
	}

	else if (scriptName == "testapp1") {
		return new TestScriptTestApp1;
	}

	else if (scriptName == "testapp2") {
		return new TestScriptTestApp2;
	}


	return nullptr;
}
