#include "TestScriptFactory.h"
#include "TestScriptReadAndCompare.h"
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
		return nullptr;
	}

	else if (scriptName == "testapp2") {
		return nullptr;
	}
}
