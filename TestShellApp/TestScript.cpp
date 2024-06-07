#include "TestScript.h"

TestScript::TestScript() {
    Command cmd1 = { "read", 1, "0x99999999"};
    Command cmd2 = { "write", 2, "0x77777777" };
    Command cmd3 = { "read", 2 };
    m_TestScriptCommandVector.push_back(cmd1);
    m_TestScriptCommandVector.push_back(cmd2);
    m_TestScriptCommandVector.push_back(cmd3);
}

void TestScript::addCommand(const Command& cmd) {
    m_TestScriptCommandVector.push_back(cmd);
}

const TestScript::TestVector_t& TestScript::getCommands() const {
    return m_TestScriptCommandVector;
}