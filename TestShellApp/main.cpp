#include <fstream>
#include <iostream>
#include <vector>

#include "Logger.h"
#include "ShellCommandHandler.h"
#include "TestScriptRunner.h"

using std::cout;
using std::vector;

class TestShellApp
{
  public:
    TestShellApp() : m_rShellCmdHdlr(ShellCommandHandler::getCommandHandler())
    {
    }

    void run(int argc, char *argv[])
    {
        if (IsPromptExeEnv(argc) == true)
            promptProcess();
        else
            fileProcess(argv);
    }

  private:
    bool IsPromptExeEnv(int argc)
    {
        return argc == 1;
    }

    void promptProcess()
    {
        cout << "*** TestShellApp version 1.0 ***\n";
        runConsole();
    }

    void fileProcess(char *argv[])
    {
        string filename{argv[1]};
        std::ifstream istrm(filename);

        if (!istrm.is_open())
        {
            std::cout << "failed to open " << filename << '\n';
            throw std::exception();
        }
        else
        {
            runScriptFile(istrm);
        }
    }

    void runConsole()
    {
        LOG_PRINT("run Console");

        while (true)
        {
            ShellCommand exportCmd;
            Result_e result = m_rShellCmdHdlr.exportCmdWithString(getConsoleInput(), &exportCmd);
            if (result == Result_e::FAIL)
            {
                std::cout << "INVALID COMMAND" << std::endl;
                continue;
            }
            if (result == Result_e::EXIT)
                break;
            executeShellCmd(exportCmd);
        }
    }

    string getConsoleInput()
    {
        string inputScript = "";
        std::cout << "> ";
        std::getline(std::cin, inputScript);
        return inputScript;
    }

    bool IsTestCaseCommand(ShellCommand &rCommand)
    {
        return rCommand.type.find("testcase") == 0;
    }

    void executeShellCmd(ShellCommand &rCommand)
    {
        if (IsTestCaseCommand(rCommand) == true)
        {
            m_testScriptRunner.setCmdVector(m_rShellCmdHdlr.getCurrentScenario()->getCommandVector());
            Result_e result = m_testScriptRunner.runTC();
            if (result == Result_e::FAIL)
                std::cout << "runTC fail" << std::endl;
            else
                std::cout << "runTC success" << std::endl;
        }
        else
        {
            m_testScriptRunner.inputShellCmd(rCommand);
            m_testScriptRunner.run();
        }
    }

    void runScriptFile(std::ifstream &istrm)
    {
        while (true)
        {
            string inputString = "";
            if (!(istrm >> inputString))
                break;

            ShellCommand exportedCmd;
            Result_e result = m_rShellCmdHdlr.exportCmdWithString(inputString, &exportedCmd);
            if (result == Result_e::FAIL)
            {
                std::cout << "INVALID COMMAND" << std::endl;
                continue;
            }

            if (result == Result_e::EXIT)
                break;

            m_testScriptRunner.inputShellCmd(exportedCmd);
            if (IsTestCaseCommand(exportedCmd) == true)
            {
                IScenario *pScenario = m_rShellCmdHdlr.getCurrentScenario();
                m_testScriptRunner.setCmdVector(pScenario->getCommandVector());
                Result_e result = m_testScriptRunner.runTC();
                if (result == Result_e::FAIL)
                {
                    std::cout << pScenario->getName() << "   ---   Run... Fail!" << std::endl;
                    break;
                }
                std::cout << pScenario->getName() << "   ---   Run... Pass" << std::endl;
            }
            else
            {
                m_testScriptRunner.inputShellCmd(exportedCmd);
                m_testScriptRunner.run();
            }
        }
    }

    ShellCommandHandler &m_rShellCmdHdlr;
    TestScriptRunner m_testScriptRunner;
};

int main(int argc, char *argv[])
{
    try
    {
        TestShellApp testShellApp;
        testShellApp.run(argc, argv);
    }
    catch (const std::exception &e)
    {
        cout << "EXCEPTION! : " << e.what() << std::endl;
    }
}
