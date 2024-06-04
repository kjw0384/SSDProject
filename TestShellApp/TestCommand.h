#pragma once
#include <string>

typedef std::string cmdType_t;
typedef int Index_t;
typedef unsigned int value_t;

struct Command {
	cmdType_t type;
	Index_t LBAIndexNum;
	value_t value;
};