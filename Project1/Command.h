#pragma once

using namespace std;
#define interface struct
interface Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};
