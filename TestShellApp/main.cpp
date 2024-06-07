#include <vector>
#include <iostream>

#include "CommandHandler.h"
#include "TestScriptRunner.h"
#include "VirtualSsdProcess.h"
#include "ResultFileReader.h"

using std::vector;
using std::cout;

static void RunMain() {
    CommandHandler& handler = CommandHandler::getCommandHandler();

    while (true) {
        string testScript = "";
        std::cout << "> ";
        std::getline(std::cin, testScript);

        Result_e result = handler.runCommand(testScript);
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
        runner->inputCmd(cmd);

        runner->run();
    }
}

int main(int argc, char* argv[]) {
    try {
        cout << "*** TestShellApp version 1.0 ***\n";
        RunMain();
    }
    catch (const std::exception& e) {
        cout << "EXCEPTION! : " << e.what() << std::endl;
    }
}
