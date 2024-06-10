#pragma once

#define interface struct

using namespace std;

interface ShellCommand {
public:
    virtual ~ShellCommand() {}
    virtual void execute() = 0;
};
