#include <vector>
#include <iostream>

#include "TestScriptParser.h"
#include "TestScriptRunner.h"
#include "VirtualSsdProcess.h"
#include "ResultFileReader.h"

using std::vector;

int main(int argc, char* argv[]) {

    vector<string> arguments;
    for (int i = 1; i < argc; i++)
    {
        arguments.push_back(argv[i]);
    }

    TestScriptParser* parser=new TestScriptParser();
    parser->executeParse(arguments);
    Command cmd=parser->getTestCmd();

    VirtaulSsdProcess* pSsdProcIf=new VirtaulSsdProcess();
    ResultFileReader* pReadResultIO= new ResultFileReader();

    TestScriptRunner* runner = new TestScriptRunner(pSsdProcIf, pReadResultIO);
    Result_e result=runner->inputCmd(cmd);
    if (result == Result_e::FAIL) return 0;
    runner->run();

    std::cout << "Run..." << std::endl;
}
