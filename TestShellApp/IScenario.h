#pragma once
#include <iostream>
#include <string>

#include "TestCommand.h"
#include <sstream>
#include <vector>

#define interface struct

using std::cout;
using namespace std;

interface IScenario
{
  public:
    typedef vector<ShellCommand> TestVector_t;

    virtual ~IScenario()
    {
    }

    virtual void run() = 0;

    string getName()
    {
        return m_name;
    }

    void setName(string name)
    {
        m_name = name;
    }

    const TestVector_t &getCommandVector() const
    {
        return m_TestScriptCommandVector;
    }

  protected:
    void addCommand(const ShellCommand &cmd)
    {
        m_TestScriptCommandVector.push_back(cmd);
    }
    ShellCommand parseCommand(const string &scenario)
    {
        ShellCommand cmd;
        istringstream iss(scenario);
        string value;

        iss >> cmd.type;
        if ((cmd.type != "fullwrite") && (cmd.type != "fullread"))
            iss >> cmd.LBAIndexNum;

        if (iss >> value)
        {
            cmd.value = value;
        }
        else
        {
            cmd.value = "";
        }

        return cmd;
    }

    string m_name;
    TestVector_t m_TestScriptCommandVector;
};
