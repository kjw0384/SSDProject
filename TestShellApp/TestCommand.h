#pragma once
#include <string>

using namespace std;

typedef std::string cmdType_t;
typedef int Index_t;
typedef string value_t;

struct Command {
	cmdType_t type;
	Index_t LBAIndexNum;
	value_t value;
};