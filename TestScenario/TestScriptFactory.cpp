#include "TestScriptFactory.h"
#include "TestScript.h"
#include <string>

TestScriptFactory &TestScriptFactory::getInstance()
{
    static TestScriptFactory testScriptFactoryInstance;
    return testScriptFactoryInstance;
}

IScenario *TestScriptFactory::createTestScript(string scriptName)
{
    if (scriptName == "ReadAndCompare")
    {
        return new TestScriptReadAndCompare;
    }
    else if (scriptName == "testapp1")
    {
        return new TestScriptTestApp1;
    }
    else if (scriptName == "testapp2")
    {
        return new TestScriptTestApp2;
    }
    else if (scriptName == "ReadFailCase")
    {
        return new TestScriptReadFailCase;
    }
    else if (scriptName == "ReadWrite")
    {
        return new TestScriptReadWrite;
    }
    else if (scriptName == "PatternMSB")
    {
        return new TestScriptPatternMSB;
    }
    else if (scriptName == "PatternLSB")
    {
        return new TestScriptPatternLSB;
    }
    else if (scriptName == "Pattern0xFFFFFFFF")
    {
        return new TestScriptPattern0xFFFFFFFF;
    }
    else if (scriptName == "Pattern0x5A5A5A5A")
    {
        return new TestScriptPattern0x5A5A5A5A;
    }
    else if (scriptName == "Pattern0xA5A5A5A5")
    {
        return new TestScriptPattern0xA5A5A5A5;
    }
    else if (scriptName == "OneBit")
    {
        return new TestScriptOneBit;
    }

    return nullptr;
}
