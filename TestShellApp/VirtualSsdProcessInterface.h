#pragma once
#include <string>
#include "TestShellCommon.h"

using std::string;

class VirtualSsdProcessInterface {
public:
	virtual Result_e sendReadIpc(const int address) = 0;
	virtual Result_e sendWriteIpc(const int address, const string data) = 0;
	virtual Result_e sendEraseIpc(const int address, const int size) = 0;
	virtual Result_e sendFlushIpc() = 0;
};
