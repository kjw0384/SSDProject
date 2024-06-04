#pragma once

#define interface struct

using namespace std;

interface Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};
