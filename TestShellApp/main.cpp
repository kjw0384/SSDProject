#include <iostream>
#include <vector>

#include "../TestScenario/TestScenario.h"
#include "CommandHandler.h"
#include "ResultFileReader.h"
#include "TestScriptRunner.h"
#include "VirtualSsdProcess.h"
#include "Logger.h"

using std::cout;
using std::vector;

void PrintTestcaseResult(Result_e result, CommandHandler& handler)
{
    if (result == Result_e::FAIL)
        std::cout << handler.scenario->getName() << "   ---   Run... Fail" << std::endl;
    else
        std::cout << handler.scenario->getName() << "   ---   Run... Pass" << std::endl;
}

static void RunCommand(CommandHandler& handler)
{
    Command cmd = handler.getCommand();
    VirtaulSsdProcess* pSsdProcIf = new VirtaulSsdProcess();
    ResultFileReader* pReadResultIO = new ResultFileReader();

    TestScriptRunner* runner = new TestScriptRunner(pSsdProcIf, pReadResultIO);
    runner->inputCmd(cmd);

    runner->setvector(handler.scenario->getCommands());
    Result_e result = runner->runTC();
    PrintTestcaseResult(result, handler);
}

static void RunMain() {
    LOG_PRINT("Run Main");
    CommandHandler& handler = CommandHandler::getCommandHandler();

    while (true) {
        string testScript = "";
        std::cout << "> ";
        std::getline(std::cin, testScript);

        Result_e result = handler.runParse(testScript);
        if (result == Result_e::FAIL) {
            std::cout << "INVALID COMMAND" << std::endl;
            continue;
        }

        if (result == Result_e::EXIT) {
            break;
        }

        Command cmd = handler.getCommand();
        VirtaulSsdProcess* pSsdProcIf = new VirtaulSsdProcess();
        ResultFileReader* pReadResultIO = new ResultFileReader();

        TestScriptRunner* runner = new TestScriptRunner(pSsdProcIf, pReadResultIO);

        if (cmd.type.find("testcase") == 0) {
            runner->setvector(handler.scenario->getCommands());
            Result_e result = runner->runTC();

            PrintTestcaseResult(result, handler);
        }
        else {
            runner->inputCmd(cmd);
            runner->run();
        }
    }
}

static void RunScript(std::ifstream &istrm)
{
    CommandHandler &handler = CommandHandler::getCommandHandler();

    while (true)
    {
        string testScript = "";
        if (!(istrm >> testScript))
            break;

        Result_e result = handler.runParse(testScript);
        if (result == Result_e::FAIL)
        {
            std::cout << "INVALID COMMAND" << std::endl;
            continue;
        }

        if (result == Result_e::EXIT)
        {
            break;
        }

        RunCommand(handler);
    }
}

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 1)
        {
            cout << "*** TestShellApp version 1.0 ***\n";
            RunMain();
        }
        else
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
                RunScript(istrm);
            }
        }
    }
    catch (const std::exception &e)
    {
        cout << "EXCEPTION! : " << e.what() << std::endl;
    }
}