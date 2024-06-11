#pragma once
#ifdef TESTSCENARIOLIBRARY_EXPORTS
#define TESTSCENARIOLIBRARY_API __declspec(dllexport)
#else
#define TESTSCENARIOLIBRARY_API __declspec(dllimport)
#endif

#include "../TestShellApp/IScenario.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class TESTSCENARIOLIBRARY_API TestScenarioAPI
{
  public:
    static IScenario *getScenario(const string &testScenarioName);
    static vector<string> getScenarios();
};
