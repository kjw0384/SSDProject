#pragma once

#include "VirtualSsdProcessInterface.h"
#include <iostream>

using namespace std;

class VirtaulSsdProcess : public VirtualSsdProcessInterface {
public:

	const string DATA_DIR = "..\\x64\\Debug\\ssd";

	Result_e sendReadIpc(const int address);
	Result_e sendWriteIpc(const int address, const string data);
	Result_e sendEraseIpc(const int address, const int size);
	Result_e sendFlushIpc();

private:

};