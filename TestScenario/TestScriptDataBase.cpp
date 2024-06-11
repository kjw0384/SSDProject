#include "TestScriptDataBase.h"
#include "../TestShellApp/IScenario.h"
#include "TestScriptFactory.h"

TestScriptDataBase::TestScriptDataBase()
{
    createTestScript("ReadAndCompare");
    createTestScript("testapp1");
    createTestScript("testapp2");
    createTestScript("ReadFailCase");
    createTestScript("ReadWrite");
    createTestScript("PatternMSB");
    createTestScript("PatternLSB");
    createTestScript("Pattern0xFFFFFFFF");
    createTestScript("Pattern0x5A5A5A5A");
    createTestScript("Pattern0xA5A5A5A5");
    createTestScript("OneBit");
}

void TestScriptDataBase::createTestScript(string testScriptName)
{
    m_TestScriptDB.push_back(TestScriptFactory::getInstance().createTestScript(testScriptName));
}

TestScriptDataBase &TestScriptDataBase::getInstance()
{
    static TestScriptDataBase testScriptDBInsatnce;
    return testScriptDBInsatnce;
}

IScenario *TestScriptDataBase::GetTestScriptCase(string TestScriptName)
{
    for (IScenario *testScriptCasetIter : m_TestScriptDB)
    {
        if (testScriptCasetIter->getName() == TestScriptName)
        {
            return testScriptCasetIter;
        }
    }
    return nullptr;
}

vector<string> TestScriptDataBase::getScenarioList()
{
    vector<string> retStrVector;
    for (IScenario *testScriptCasetIter : m_TestScriptDB)
    {
        retStrVector.push_back(testScriptCasetIter->getName());
    }
    return retStrVector;
}
