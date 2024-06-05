#pragma once

#include "VirtualSsdProcessInterface.h"
#include <iostream>

using namespace std;

class VirtaulSsdProcess : public VirtualSsdProcessInterface {
public:
	Result_e sendReadIpc(const int address);
	Result_e sendWriteIpc(const int address, const string data);

private:

};