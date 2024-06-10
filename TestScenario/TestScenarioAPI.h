#pragma once
#ifdef TESTSCENARIOLIBRARY_EXPORTS
#define TESTSCENARIOLIBRARY_API __declspec(dllexport)
#else
#define TESTSCENARIOLIBRARY_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include "../TestShellApp/IScenario.h"

using std::string;
using std::vector;

class TESTSCENARIOLIBRARY_API TestScenarioAPI {
public:
    //TestScenario();
    static IScenario* getScenario(const string& testScenarioName);
    static vector<string> getScenarios();
};