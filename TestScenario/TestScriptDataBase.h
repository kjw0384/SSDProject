#pragma once

#include "../TestShellApp/IScenario.h"
#include <string>
#include <vector>

using namespace std;

class TestScriptDataBase
{
  public:
    static TestScriptDataBase &getInstance();

    void createTestScript(string testScriptName);
    IScenario *GetTestScriptCase(string TestScriptName);
    vector<string> getScenarioList();

  private:
    TestScriptDataBase();
    vector<IScenario *> m_TestScriptDB;
};
