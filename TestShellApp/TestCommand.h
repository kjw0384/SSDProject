#pragma once
#include <string>

using namespace std;

typedef std::string ShellCmdType_t;
typedef int Index_t;
typedef std::string value_t;
typedef int Size_t;

static const int MIN_LBA = 0;
static const int MAX_LBA = 100;

struct ShellCommand
{
    ShellCmdType_t type;
    Index_t LBAIndexNum;
    value_t value;
    Size_t size;
};
