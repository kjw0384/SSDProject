#pragma once
#include <string>

using namespace std;

typedef std::string cmdType_t;
typedef int Index_t;
typedef std::string value_t;
typedef int Size_t;

const int MIN_LBA = 0;
const int MAX_LBA = 100;

struct Command {
	cmdType_t type;
	Index_t LBAIndexNum;
	value_t value;
	Size_t size;
};