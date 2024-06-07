#pragma once

#include <vector>
#include "TestCommand.h"

using namespace std;

class TestScript {
public:
    typedef vector<Command> TestVector_t;

    TestScript();

    void addCommand(const Command& cmd);
    const TestVector_t& getCommands() const;
    TestVector_t m_TestScriptCommandVector;
private:

};
