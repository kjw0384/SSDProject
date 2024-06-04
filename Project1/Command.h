#pragma once

using namespace std;

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};
