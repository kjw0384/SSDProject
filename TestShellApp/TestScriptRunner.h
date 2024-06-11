#pragma once

#include <string>
#include <vector>

#include "ReadIOInterface.h" //TODO: sync to readio
#include "TestCommand.h"
#include "TestShellCommon.h"
#include "VirtualSsdProcessInterface.h"

using namespace std;

class TestScriptRunner
{
  public:
    typedef vector<ShellCommand> TestVector_t;

    explicit TestScriptRunner();
    explicit TestScriptRunner(VirtualSsdProcessInterface *pSsdProcInterface, ReadIOInterface *pReadIOInterface);
    Result_e inputShellCmd(ShellCommand &cmd);
    Result_e run();
    Result_e runTC();
    void setCmdVector(TestVector_t vector);

  private:
    Result_e callSsdProcess(ShellCommand cmd);
    Result_e callSsdProcessAndCompare(ShellCommand cmd);
    Result_e callSsdProcessInternal(ShellCommand cmd);

    TestVector_t m_ShellCmdVector;
    VirtualSsdProcessInterface *m_ssdProcessIf;
    ReadIOInterface *m_ReadResultIO;
};
