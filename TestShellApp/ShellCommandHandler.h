#pragma once

#include "../TestScenario/TestScenarioAPI.h"
#include "TestCommand.h"
#include "TestScriptParser.h"
#include "TestScriptValidChecker.h"

class ShellCommandHandler
{
  public:
    static ShellCommandHandler &getCommandHandler()
    {
        static ShellCommandHandler commandHandler;
        return commandHandler;
    }

    IScenario *getCurrentScenario();
    ShellCommand getCurrentCommand();

    Result_e exportCmdWithString(const string &testScript, ShellCommand *retCmd);

  private:
    ShellCommandHandler() : m_pCurScenario(nullptr)
    {
    }
    ShellCommandHandler &operator=(const ShellCommandHandler &other) = delete;
    ShellCommandHandler(const ShellCommandHandler &other) = delete;

    void handleHelp();
    void handleScenario(const string &testScenario, TestScenarioAPI &scenarioLib);

    TestScriptValidChecker m_ValidChecker;
    TestScriptParser m_Parser;

    IScenario *m_pCurScenario;
    ShellCommand m_curCmd;
};
