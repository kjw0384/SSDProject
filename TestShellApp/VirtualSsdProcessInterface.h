#pragma once

#include "TestShellCommon.h"

class VirtualSsdProcessInterface {
public:
	virtual Result_e sendReadIpc(const int address) = 0;
	virtual Result_e sendWriteIpc(const int address, const string data) = 0;
};
